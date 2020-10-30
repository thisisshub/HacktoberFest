#include "speck128.h"

void SpeckKeySchedule(u64 K[], u64 rk[])
{
    u64 i, C = K[2], B = K[1], A = K[0];
    for (i = 0; i < 32;)
    {
        rk[i] = A;
        ER64(B, A, i++);
        rk[i] = A;
        ER64(C, A, i++);
    }
    rk[i] = A;
}
void SpeckEncrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    u64 i;
    Ct[0] = Pt[0];
    Ct[1] = Pt[1];
    for (i = 0; i < 33;)
        ER64(Ct[1], Ct[0], rk[i++]);
}

void SpeckDecrypt(u64 Pt[], u64 Ct[], u64 rk[])
{
    int i;
    Pt[0] = Ct[0];
    Pt[1] = Ct[1];
    for (i = 32; i >= 0;)
        DR64(Pt[1], Pt[0], rk[i--]);
}