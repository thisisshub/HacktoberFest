#include "ctr.h"
#include "../common/utils.h"
#include <stdlib.h>
#include <string.h>

#define DEBUG

void xor (u8 * in, u8 *out, int length) {
    for (int i = 0; i < length; i++)
    {
        out[i] ^= in[i];
    }
}

    void byteAdd(u8 *dst, int dstLength, u8 *count)
{
    int carry = 0;

    for (int i = 0; i < dstLength; i++)
    {
        u8 odst = dst[i];
        u8 osrc = i < dstLength ? count[i] : (u8)0;

        int ndst = (u8)(odst + osrc + carry);
        dst[i] = ndst;
        carry = ndst < odst ? 1 : 0;
    }
}

/**
 * For every block:
 * 1. Concat/xor/add nonce  with counter (random nonce)
 * 2. Encrypt nonce
 * 3. XOR between encrypted nonce and plain
 * 4. Increment counter
 */
void ctrEncrypt64(cypher64 cypher, u8 *nonce, u8 *plaintext, u8 length, u32 *rk)
{
    int block = 0;
    int last_block;
    u8 counter[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    u32 Pt[2];
    u32 Ct[2];
    u8 workingNonce[cypher.blockSize];
    u8 ct[cypher.blockSize];

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION \\ DECRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("===================================================\n");
#endif

    last_block = length - cypher.blockSize;
#ifdef DEBUG
    printf("Last block size: %d\n", last_block);
    printf("===================================================\n");

#endif

    if (length > cypher.blockSize)
    {
        for (block = 0; block < last_block; block += cypher.blockSize)
        {
            //STEP 1
            memcpy(workingNonce, nonce, cypher.blockSize);
            xor(counter, workingNonce, cypher.blockSize);

#ifdef DEBUG
            printf("Block number: %d \n", block / cypher.blockSize);
            printf("Counter: \n");
            hex_print(counter, 0, cypher.blockSize);
            printf("Nonce: \n");
            hex_print(nonce, 0, cypher.blockSize);
            printf("counter xor nonce:\n");
            hex_print(workingNonce, 0, cypher.blockSize);
            printf("===================================================\n");
#endif

            //STEP 2
            BytesToWords32(workingNonce, Pt, cypher.blockSize);
            cypher.encrypt(Pt, Ct, rk);
            Words32ToBytes(Ct, ct, 2);

#ifdef DEBUG
            printf("Encrypted nonce: \n");
            hex_print(ct, 0, cypher.blockSize);
            printf("Plaintext block\\ Ciphertext block: \n");
            hex_print(plaintext, block, block + cypher.blockSize);
            printf("===================================================\n");

#endif

            //STEP3
            xor(ct, &plaintext[block], cypher.blockSize);
#ifdef DEBUG
            printf("Xored plaintext block \\ ciphertext block: \n");
            hex_print(plaintext, block, block + cypher.blockSize);
            printf("===================================================\n");

#endif
            //STEP 4
            u8 count[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
            byteAdd(counter, cypher.blockSize, count);
        }
    }

    /*******************************last block**********************************/

    //STEP 1
    memcpy(workingNonce, nonce, cypher.blockSize);
    xor(counter, workingNonce, cypher.blockSize);
#ifdef DEBUG
    printf("Block number: %d \n", block / cypher.blockSize);
    printf("Counter: \n");
    hex_print(counter, 0, cypher.blockSize);
    printf("Nonce: \n");
    hex_print(nonce, 0, cypher.blockSize);
    printf("counter xor nonce:\n");
    hex_print(workingNonce, 0, cypher.blockSize);
    printf("===================================================\n");
#endif

    //STEP 2

    BytesToWords32(workingNonce, Pt, cypher.blockSize);
    cypher.encrypt(Pt, Ct, rk);
    Words32ToBytes(Ct, ct, 2);

#ifdef DEBUG
    printf("Encrypted nonce: \n");
    hex_print(ct, 0, cypher.blockSize);
    printf("Plaintext block \\ Ciphertext block: \n");
    hex_print(plaintext, block, block + cypher.blockSize);
    printf("===================================================\n");

#endif

    //STEP3
    xor(ct, &plaintext[block], length - block);

#ifdef DEBUG
    printf("Xored plaintext block \\ ciphertext block: \n");
    hex_print(plaintext, block, block + cypher.blockSize);
    printf("===================================================\n");

#endif

#ifdef DEBUG
    printf("Plaintext \\ Ciphertext: \n");
    hex_print(plaintext, 0, length);
    printf("=======END DEBUG ENCRYPTION \\ DECRYPTION:==========\n");

#endif
}

void ctrDecrypt64(cypher64 cypher, u8 *nonce, u8 *ciphertext, u8 length, u32 *rk)
{
    ctrEncrypt64(cypher, nonce, ciphertext, length, rk);
}

void ctrEncrypt128(cypher128 cypher, u8 *nonce, u8 *plaintext, u8 length, u64 *rk)
{
    int block = 0;
    int last_block;
    u8 counter[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    u64 Pt[2];
    u64 Ct[2];
    u8 workingNonce[cypher.blockSize];
    u8 ct[cypher.blockSize];

#ifdef DEBUG
    printf("======START DEBUG ENCRYPTION \\ DECRYPTION:========\n");
    printf("Size mex: %d\n", length);
    printf("Block size: %d\n", cypher.blockSize);
    printf("===================================================\n");
#endif

    last_block = length - cypher.blockSize;
#ifdef DEBUG
    printf("Last block size: %d\n", last_block);
    printf("===================================================\n");

#endif

    if (length > cypher.blockSize)
    {
        for (block = 0; block < last_block; block += cypher.blockSize)
        {
            //STEP 1
            memcpy(workingNonce, nonce, cypher.blockSize);
            xor(counter, workingNonce, cypher.blockSize);

#ifdef DEBUG
            printf("Block number: %d \n", block / cypher.blockSize);
            printf("Counter: \n");
            hex_print(counter, 0, cypher.blockSize);
            printf("Nonce: \n");
            hex_print(nonce, 0, cypher.blockSize);
            printf("counter xor nonce:\n");
            hex_print(workingNonce, 0, cypher.blockSize);
            printf("===================================================\n");
#endif

            //STEP 2
            BytesToWords64(workingNonce, Pt, cypher.blockSize);
            cypher.encrypt(Pt, Ct, rk);
            Words64ToBytes(Ct, ct, 2);

#ifdef DEBUG
            printf("Encrypted nonce: \n");
            hex_print(ct, 0, cypher.blockSize);
            printf("Plaintext block\\ Ciphertext block: \n");
            hex_print(plaintext, block, block + cypher.blockSize);
            printf("===================================================\n");

#endif

            //STEP3
            xor(ct, &plaintext[block], cypher.blockSize);
#ifdef DEBUG
            printf("Xored plaintext block \\ ciphertext block: \n");
            hex_print(plaintext, block, block + cypher.blockSize);
            printf("===================================================\n");

#endif
            //STEP 4
            u8 count[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
            byteAdd(counter, cypher.blockSize, count);
        }
    }

    /*******************************last block**********************************/

    //STEP 1
    memcpy(workingNonce, nonce, cypher.blockSize);
    xor(counter, workingNonce, cypher.blockSize);
#ifdef DEBUG
    printf("Block number: %d \n", block / cypher.blockSize);
    printf("Counter: \n");
    hex_print(counter, 0, cypher.blockSize);
    printf("Nonce: \n");
    hex_print(nonce, 0, cypher.blockSize);
    printf("counter xor nonce:\n");
    hex_print(workingNonce, 0, cypher.blockSize);
    printf("===================================================\n");
#endif

    //STEP 2

    BytesToWords64(workingNonce, Pt, cypher.blockSize);
    cypher.encrypt(Pt, Ct, rk);
    Words64ToBytes(Ct, ct, 2);

#ifdef DEBUG
    printf("Encrypted nonce: \n");
    hex_print(ct, 0, cypher.blockSize);
    printf("Plaintext block \\ Ciphertext block: \n");
    hex_print(plaintext, block, block + cypher.blockSize);
    printf("===================================================\n");

#endif

    //STEP3
    xor(ct, &plaintext[block], length - block);

#ifdef DEBUG
    printf("Xored plaintext block \\ ciphertext block: \n");
    hex_print(plaintext, block, block + cypher.blockSize);
    printf("===================================================\n");

#endif

#ifdef DEBUG
    printf("Plaintext \\ Ciphertext: \n");
    hex_print(plaintext, 0, length);
    printf("=======END DEBUG ENCRYPTION \\ DECRYPTION:==========\n");

#endif
}

void ctrDecrypt128(cypher128 cypher, u8 *nonce, u8 *ciphertext, u8 length, u64 *rk)
{
    ctrEncrypt128(cypher, nonce, ciphertext, length, rk);
}
