#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>

#define u8 uint8_t
#define u32 uint32_t
#define u64 uint64_t

#define ROTL32(x, r) (((x) << (r)) | (x >> (32 - (r))))
#define ROTR32(x, r) (((x) >> (r)) | ((x) << (32 - (r))))

#define f32(x) ((ROTL32(x, 1) & ROTL32(x, 8)) ^ ROTL32(x, 2))
#define R32x2(x, y, k1, k2) (y ^= f32(x), y ^= k1, x ^= f32(y), x ^= k2)

#define ER32(x, y, k) (x = ROTR32(x, 8), x += y, x ^= k, y = ROTL32(y, 3), y ^= x)
#define DR32(x, y, k) (y ^= x, y = ROTR32(y, 3), x ^= k, x -= y, x = ROTL32(x, 8))

#define ROTL64(x, r) (((x) << (r)) | (x >> (64 - (r))))
#define ROTR64(x, r) (((x) >> (r)) | ((x) << (64 - (r))))

#define f64(x) ((ROTL64(x, 1) & ROTL64(x, 8)) ^ ROTL64(x, 2))
#define R64x2(x, y, k1, k2) (y ^= f64(x), y ^= k1, x ^= f64(y), x ^= k2)

#define ER64(x, y, s) (x = (ROTR64(x, 8) + y) ^ (s), y = ROTL64(y, 3) ^ x)
#define DR64(x, y, k) (y ^= x, y = ROTR64(y, 3), x ^= k, x -= y, x = ROTL64(x, 8))

/**
 * Struct for cypher
 */
typedef struct
{
    void (*encrypt)(u32 Pt[], u32 Ct[], u32 rk[]);
    void (*decrypt)(u32 Pt[], u32 Ct[], u32 rk[]);
    void (*keySchedule)(u32 K[], u32 rk[]);
    u8 blockSize;

} cypher64;

typedef struct
{
    void (*encrypt)(u64 Pt[], u64 Ct[], u64 rk[]);
    void (*decrypt)(u64 Pt[], u64 Ct[], u64 rk[]);
    void (*keySchedule)(u64 K[], u64 rk[]);
    u8 blockSize;

} cypher128;

#endif
