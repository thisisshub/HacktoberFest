//#define SPECK6496
//#define SPECK64128
//#define SPECK128128
//#define SPECK128192
//#define SPECK128256
//#define SIMON6496
//#define SIMON64128
//#define SIMON128128
#define SIMON128192
//#define SIMON128256

#ifdef SPECK6496
#include "speck/speck6496.c"
#define SPECK
#define S64
#define BLOCK_SIZE 8 // 2 X 4 => 2 X 32 bits
#define MEX_LEN 8
#define KEY_LEN 12
#define KEY 3
#define KEY_ROUND 26
#endif

#ifdef SPECK64128
#include "speck/speck64128.c"
#define SPECK
#define S64
#define BLOCK_SIZE 8 // 2 X 4 => 2 X 32 bits
#define MEX_LEN 8
#define KEY_LEN 16
#define KEY 4
#define KEY_ROUND 27
#endif

#ifdef SPECK128128
#include "speck/speck128128.c"
#define SPECK
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 16
#define KEY 2
#define KEY_ROUND 32
#endif

#ifdef SPECK128192
#include "speck/speck128192.c"
#define SPECK
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 24
#define KEY 3
#define KEY_ROUND 33
#endif

#ifdef SPECK128256
#include "speck/speck128256.c"
#define SPECK
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 32
#define KEY 4
#define KEY_ROUND 34
#endif

#ifdef SIMON6496
#include "simon/simon6496.c"
#define SIMON
#define S64
#define BLOCK_SIZE 8 // 2 X 4 => 2 X 32 bits
#define MEX_LEN 8
#define KEY_LEN 12
#define KEY 3
#define KEY_ROUND 42
#endif

#ifdef SIMON64128
#include "simon/simon64128.c"
#define SIMON
#define S64
#define BLOCK_SIZE 8 // 2 X 4 => 2 X 32 bits
#define MEX_LEN 8
#define KEY_LEN 16
#define KEY 4
#define KEY_ROUND 44
#endif

#ifdef SIMON128128
#include "simon/simon128128.c"
#define SIMON
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 16
#define KEY 2
#define KEY_ROUND 68
#endif

#ifdef SIMON128192
#include "simon/simon128192.c"
#define SIMON
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 24
#define KEY 3
#define KEY_ROUND 69
#endif

#ifdef SIMON128256
#include "simon/simon128256.c"
#define SIMON
#define S128
#define BLOCK_SIZE 16 // 2 X 8 => 2 X 64 bits
#define MEX_LEN 16
#define KEY_LEN 32
#define KEY 4
#define KEY_ROUND 72
#endif

#include "common/utils.h"
#include "mode/ctr.c"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main()
{
#ifdef S64
        cypher64 *cypher = malloc(sizeof(cypher64));
        if (cypher != NULL)
        {
                cypher->blockSize = BLOCK_SIZE;
#ifdef SPECK
                cypher->encrypt = &SpeckEncrypt;
                cypher->decrypt = &SpeckDecrypt;
                cypher->keySchedule = &SpeckKeySchedule;
#else
                cypher->encrypt = &SimonEncrypt;
                cypher->decrypt = &SimonDecrypt;
                cypher->keySchedule = &SimonKeySchedule;
#endif
        }
        else
        {
                printf("Some errors");
                return 1;
        }
        u8 pt[] = {0x65, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74,
                   0xeb, 0x7d, 0x4b, 0x75, 0xba, 0x00, 0x00, 0x02,
                   0x65, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74,
                   0xeb, 0x7d, 0x4b, 0x75, 0xba, 0x00, 0x00, 0x02,
                   0xff, 0xfd};

        u8 k[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b, 0x10, 0x11, 0x12, 0x13};
        u8 iv[MEX_LEN] = {0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x0a, 0x0b};
        u32 rk[KEY_ROUND];
        u32 K[KEY];
        u8 ct[sizeof(pt)];

        BytesToWords32(k, K, KEY_LEN);

#else
        cypher128 *cypher = malloc(sizeof(cypher128));
        if (cypher != NULL)
        {
                cypher->blockSize = BLOCK_SIZE;
#ifdef SPECK
                cypher->encrypt = &SpeckEncrypt;
                cypher->decrypt = &SpeckDecrypt;
                cypher->keySchedule = &SpeckKeySchedule;
#else
                cypher->encrypt = &SimonEncrypt;
                cypher->decrypt = &SimonDecrypt;
                cypher->keySchedule = &SimonKeySchedule;
#endif
        }
        else
        {
                printf("Some errors");
                return 1;
        }
        u8 k[KEY_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

        u8 pt[] = {
            0x65, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74, 0xeb, 0x7d, 0x4b, 0x75, 0xba, 0x00, 0x00, 0x02,
            0x78, 0x61, 0x6e, 0x73, 0x20, 0x46, 0x61, 0x74, 0xeb, 0x7d, 0x4b, 0x75, 0xba, 0x05, 0x05, 0x05,
            0x03};

        u8 iv[MEX_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

        u64 rk[KEY_ROUND];
        u64 K[KEY];
        u8 ct[sizeof(pt)];

        BytesToWords64(k, K, sizeof(k));

#endif

#ifdef S64
        cypher->keySchedule(K, rk);

        ctrEncrypt64(*cypher, iv, pt, sizeof(pt), rk);

        memcpy(ct, pt, sizeof(pt));
        hex_print((u8 *)ct, 0, sizeof(ct));

        ctrDecrypt64(*cypher, iv, ct, sizeof(ct), rk);

        memcpy(pt, ct, sizeof(pt)); //just for test
        hex_print(pt, 0, sizeof(pt));

#else
        cypher->keySchedule(K, rk);

        ctrEncrypt128(*cypher, iv, pt, sizeof(pt), rk);

        memcpy(ct, pt, sizeof(ct));
        hex_print(ct, 0, sizeof(ct));

        ctrDecrypt128(*cypher, iv, ct, sizeof(ct), rk);

        memcpy(pt, ct, sizeof(pt)); //just for test
        hex_print(pt, 0, sizeof(pt));

#endif
        free(cypher);
}