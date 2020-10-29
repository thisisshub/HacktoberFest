#include "simon64.h"

void SimonKeySchedule(u32 K[], u32 rk[])
{
    u32 i, c = 0xfffffffc;
    u64 z = 0x7369f885192c0ef5LL;
    rk[0] = K[0];
    rk[1] = K[1];
    rk[2] = K[2];
    for (i = 3; i < 42; i++)
    {
        rk[i] = c ^ (z & 1) ^ rk[i - 3] ^ ROTR32(rk[i - 1], 3) ^ ROTR32(rk[i - 1], 4);
        z >>= 1;
    }
}

void SimonEncrypt(u32 Pt[], u32 Ct[], u32 rk[])
{
    u32 i;
    Ct[1] = Pt[1];
    Ct[0] = Pt[0];
    for (i = 0; i < 42;)
        R32x2(Ct[1], Ct[0], rk[i++], rk[i++]);
}

void SimonDecrypt(u32 Pt[], u32 Ct[], u32 rk[])
{
    int i;
    Pt[1] = Ct[1];
    Pt[0] = Ct[0];
    for (i = 41; i >= 0;)
        R32x2(Pt[0], Pt[1], rk[i--], rk[i--]);
}