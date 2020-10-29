#include "cbc.h"
#include "../common/utils.h"

#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#include <stdio.h>
#endif

int padding(int blockSize, u8 length)
{
    return (length % blockSize == 0) ? blockSize : blockSize - (length % blockSize);
}

//TODO improve pad
void cbcEncrypt64(cypher64 cypher, u8 *iv, u8 *plaintext, u8 *ciphertext, u8 length, u32 *rk)
{

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("=====================================\n");
#endif

    //PKcS#7 padding
    int pad = padding(cypher.blockSize, length);
    u8 plaintextPadded[length + pad];
    memcpy(plaintextPadded, plaintext, length);
    for (int i = length; i < length + pad; i++)
    {
        plaintextPadded[i] = pad;
    }

    //compute the number of block
    int blocks = sizeof(plaintextPadded) / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("=====================================\n");
#endif
    /**
    * For every block:
    * 1. xor between iv and n bytes of plaintext
    * 2. split xored bytes 
    * 3. encrypt
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {
#ifdef DEBUG
        printf("Block: %d\n", i);
        printf("plain: ");
        hex_print((u8 *)plaintextPadded, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif
        /**
         * STEP 1
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            //  printf("%x\n", iv[c]);
            plaintextPadded[(c) + (cypher.blockSize * i)] ^= iv[c];
        }

#ifdef DEBUG
        printf("iv: ");
        hex_print(iv, 0, cypher.blockSize);
        printf("Xored: ");
        hex_print((u8 *)plaintextPadded, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif

        /**
         * STEP 2
         */
        u32 Pt[2];
        BytesToWords32(&plaintextPadded[i * cypher.blockSize], Pt, cypher.blockSize);

        /**
         * STEP 3
         */
        u32 Ct[2];
        cypher.encrypt(Pt, Ct, rk);

#ifdef DEBUG
        printf("cypher: ");
        hex_print((u8 *)Ct, 0, cypher.blockSize);
        printf("=====================================\n");
#endif

        /**
         * STEP 4
         */
        //u8 ct[16];
        //Words32ToBytes(Ct, ct, 2);
        memcpy(iv, (u8 *)Ct, cypher.blockSize);

        /**
         *  STEP 5
         */
        memcpy(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);
    }
}

int cbcDecrypt64(cypher64 cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u32 *rk)
{
#ifdef DEBUG
    printf("======START DEBUG DECRYPT:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("==================================\n");
#endif

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("==================================\n");
#endif
    /**
    * For every block:
    * 1. split ciphertext word
    * 2. decrypt
    * 3. xor between cypher and iv
    * 4. copy block
    * 5. update iv
    */
    for (int i = 0; i < blocks; i++)
    {

#ifdef DEBUG
        printf("cypher: ");
        hex_print(&ciphertext[i * cypher.blockSize], 0, cypher.blockSize);
        printf("iv: ");
        hex_print((u8 *)iv, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif

        /**
         * STEP 1
         */
        u32 Ct[2];
        BytesToWords32(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);

        /**
         * STEP 2
         */
        u32 Pt[2];
        u8 pt[8];
        cypher.decrypt(Pt, Ct, rk);
        Words32ToBytes(Pt, pt, 2);

        /**
         * STEP 4
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            pt[c] ^= iv[c];
        }

        memcpy(&plaintext[i * cypher.blockSize], pt, cypher.blockSize);

        /**
         * STEP 5
         */
        memcpy(iv, &ciphertext[i * cypher.blockSize], cypher.blockSize);
#ifdef DEBUG
        printf("xored: ");
        hex_print((u8 *)pt, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
        printf("plain: ");
        hex_print((u8 *)plaintext, 0, cypher.blockSize);
        printf("==================================\n");
#endif
    }

    //return size of plaintext without pad
    return length - plaintext[length - 1];
}

void cbcEncrypt128(cypher128 cypher, u8 *iv, u8 *plaintext, u8 *ciphertext, u8 length, u64 *rk)
{

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("=====================================\n");
#endif

    //PKcS#7 padding
    int pad = padding(cypher.blockSize, length);
    u8 plaintextPadded[length + pad];
    memcpy(plaintextPadded, plaintext, length);
    for (int i = length; i < length + pad; i++)
    {
        plaintextPadded[i] = pad;
    }

    //compute the number of block
    int blocks = sizeof(plaintextPadded) / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("=====================================\n");
#endif
    /**
    * For every block:
    * 1. xor between iv and n bytes of plaintext
    * 2. split xored bytes 
    * 3. encrypt
    * 4. update iv
    * 5. copy block
    */
    for (int i = 0; i < blocks; i++)
    {
#ifdef DEBUG
        printf("Block: %d\n", i);
        printf("plain: ");
        hex_print((u8 *)plaintextPadded, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif
        /**
         * STEP 1
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            //  printf("%x\n", iv[c]);
            plaintextPadded[(c) + (cypher.blockSize * i)] ^= iv[c];
        }

#ifdef DEBUG
        printf("iv: ");
        hex_print(iv, 0, cypher.blockSize);
        printf("Xored: ");
        hex_print((u8 *)plaintextPadded, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif

        /**
         * STEP 2
         */
        u64 Pt[2];
        BytesToWords64(&plaintextPadded[i * cypher.blockSize], Pt, cypher.blockSize);

        /**
         * STEP 3
         */
        u64 Ct[2];
        cypher.encrypt(Pt, Ct, rk);

#ifdef DEBUG
        printf("cypher: ");
        hex_print((u8 *)Ct, 0, cypher.blockSize);
        printf("=====================================\n");
#endif

        /**
         * STEP 4
         */
        memcpy(iv, (u8 *)Ct, cypher.blockSize);

        /**
         *  STEP 5
         */
        memcpy(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);
    }
}

int cbcDecrypt128(cypher128 cypher, u8 *iv, u8 *ciphertext, u8 *plaintext, u8 length, u64 *rk)
{
#ifdef DEBUG
    printf("======START DEBUG DECRYPT:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("==================================\n");
#endif

    //compute the number of block
    int blocks = length / cypher.blockSize;

#ifdef DEBUG
    printf("Number of block: %d\n", blocks);
    printf("==================================\n");
#endif
    /**
    * For every block:
    * 1. split ciphertext word
    * 2. decrypt
    * 3. xor between cypher and iv
    * 4. copy block
    * 5. update iv
    */
    for (int i = 0; i < blocks; i++)
    {

#ifdef DEBUG
        printf("cypher: ");
        hex_print(&ciphertext[i * cypher.blockSize], 0, cypher.blockSize);
        printf("iv: ");
        hex_print((u8 *)iv, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
#endif

        /**
         * STEP 1
         */
        u64 Ct[2];
        BytesToWords64(&ciphertext[i * cypher.blockSize], Ct, cypher.blockSize);

        /**
         * STEP 2
         */
        u64 Pt[2];
        u8 pt[16];
        cypher.decrypt(Pt, Ct, rk);
        Words64ToBytes(Pt, pt, 2);

        /**
         * STEP 4
         */
        for (int c = 0; c < cypher.blockSize; c++)
        {
            pt[c] ^= iv[c];
        }

        memcpy(&plaintext[i * cypher.blockSize], pt, cypher.blockSize);

        /**
         * STEP 5
         */
        memcpy(iv, &ciphertext[i * cypher.blockSize], cypher.blockSize);
#ifdef DEBUG
        printf("xored: ");
        hex_print((u8 *)pt, i * cypher.blockSize, cypher.blockSize + (i * cypher.blockSize));
        printf("plain: ");
        hex_print((u8 *)plaintext, 0, cypher.blockSize);
        printf("==================================\n");
#endif
    }

    //return size of plaintext without pad
    return length - plaintext[length - 1];
}