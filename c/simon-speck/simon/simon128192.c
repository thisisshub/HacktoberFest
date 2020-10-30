#include "simon128.h"

void SimonKeySchedule(u64 K[], u64 rk[])
{
    u64 i, C = K[2], B = K[1], A = K[0];
    u64 c = 0xfffffffffffffffcLL, z = 0xfc2ce51207a635dbLL;
    for (i = 0; i < 63;)
    {
        rk[i++] = A;
        A ^= c ^ (z & 1) ^ ROTR64(C, 3) ^ ROTR64(C, 4);
        z >>= 1;
        rk[i++] = B;
        B ^= c ^ (z & 1) ^ ROTR64(A, 3) ^ ROTR64(A, 4);
        z >>= 1;
        rk[i++] = C;
        C ^= c ^ (z & 1) ^ ROTR64(B, 3) ^ ROTR64(B, 4);
        z >>= 1;
    }
    rk[63] = A;
    A ^= c ^ 1 ^ ROTR64(C, 3) ^ ROTR64(C, 4);
    rk[64] = B;
    B ^= c ^ 0 ^ ROTR64(A, 3) ^ ROTR64(A, 4);
    rk[65] = C;
    C ^= c ^ 1 ^ ROTR64(B, 3) ^ ROTR64(B, 4);
    rk[66] = A;
    rk[67] = B;
    rk[68] = C;
}

void SimonEncrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    u64 i, t;
    Ct[0] = Pt[0];
    Ct[1] = Pt[1];
    for (i = 0; i < 68; i += 2)
        R64x2(Ct[1], Ct[0], rk[i], rk[i + 1]);
    t = Ct[1];
    Ct[1] = Ct[0] ^ f64(Ct[1]) ^ rk[68];
    Ct[0] = t;
}

void SimonDecrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    int i;
    u64 t;
    Pt[0] = Ct[0];
    Pt[1] = Ct[1];
    t = Pt[0];
    Pt[0] = Pt[1] ^ f64(Pt[0]) ^ rk[68];
    Pt[1] = t;
    for (i = 67; i >= 0; i -= 2)
        R64x2(Pt[0], Pt[1], rk[i], rk[i - 1]);
}