#include "simon128.h"

void SimonKeySchedule(u64 K[], u64 rk[])
{
    u64 i, D = K[3], C = K[2], B = K[1], A = K[0];
    u64 c = 0xfffffffffffffffcLL, z = 0xfdc94c3a046d678bLL;
    for (i = 0; i < 64;)
    {
        rk[i++] = A;
        A ^= c ^ (z & 1) ^ ROTR64(D, 3) ^ ROTR64(D, 4) ^ B ^ ROTR64(B, 1);
        z >>= 1;
        rk[i++] = B;
        B ^= c ^ (z & 1) ^ ROTR64(A, 3) ^ ROTR64(A, 4) ^ C ^ ROTR64(C, 1);
        z >>= 1;
        rk[i++] = C;
        C ^= c ^ (z & 1) ^ ROTR64(B, 3) ^ ROTR64(B, 4) ^ D ^ ROTR64(D, 1);
        z >>= 1;
        rk[i++] = D;
        D ^= c ^ (z & 1) ^ ROTR64(C, 3) ^ ROTR64(C, 4) ^ A ^ ROTR64(A, 1);
        z >>= 1;
    }
    rk[64] = A;
    A ^= c ^ 0 ^ ROTR64(D, 3) ^ ROTR64(D, 4) ^ B ^ ROTR64(B, 1);
    rk[65] = B;
    B ^= c ^ 1 ^ ROTR64(A, 3) ^ ROTR64(A, 4) ^ C ^ ROTR64(C, 1);
    rk[66] = C;
    C ^= c ^ 0 ^ ROTR64(B, 3) ^ ROTR64(B, 4) ^ D ^ ROTR64(D, 1);
    rk[67] = D;
    D ^= c ^ 0 ^ ROTR64(C, 3) ^ ROTR64(C, 4) ^ A ^ ROTR64(A, 1);
    rk[68] = A;
    rk[69] = B;
    rk[70] = C;
    rk[71] = D;
}
void SimonEncrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    u64 i;
    Ct[0] = Pt[0];
    Ct[1] = Pt[1];
    for (i = 0; i < 72; i += 2)
        R64x2(Ct[1], Ct[0], rk[i], rk[i + 1]);
}
void SimonDecrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    int i;
    Pt[0] = Ct[0];
    Pt[1] = Ct[1];
    for (i = 71; i >= 0; i -= 2)
        R64x2(Pt[0], Pt[1], rk[i], rk[i - 1]);
}