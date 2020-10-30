#include "simon128.h"

void SimonKeySchedule(u64 K[], u64 rk[])
{
    u64 i, B = K[1], A = K[0];
    u64 c = 0xfffffffffffffffcLL, z = 0x7369f885192c0ef5LL;
    for (i = 0; i < 64;)
    {
        rk[i++] = A;
        A ^= c ^ (z & 1) ^ ROTR64(B, 3) ^ ROTR64(B, 4);
        z >>= 1;
        rk[i++] = B;
        B ^= c ^ (z & 1) ^ ROTR64(A, 3) ^ ROTR64(A, 4);
        z >>= 1;
    }
    rk[64] = A;
    A ^= c ^ 1 ^ ROTR64(B, 3) ^ ROTR64(B, 4);
    rk[65] = B;
    B ^= c ^ 0 ^ ROTR64(A, 3) ^ ROTR64(A, 4);
    rk[66] = A;
    rk[67] = B;
}

void SimonEncrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    u64 i;
    Ct[0] = Pt[0];
    Ct[1] = Pt[1];
    for (i = 0; i < 68; i += 2)
        R64x2(Ct[1], Ct[0], rk[i], rk[i + 1]);
}

void SimonDecrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    int i;
    Pt[0] = Ct[0];
    Pt[1] = Ct[1];
    for (i = 67; i >= 0; i -= 2)
        R64x2(Pt[0], Pt[1], rk[i], rk[i - 1]);
}
