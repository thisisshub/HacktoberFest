#include "speck64.h"

void SpeckKeySchedule(u32 K[], u32 rk[])
{
    u32 i, C = K[2], B = K[1], A = K[0];
    for (i = 0; i < 26;)
    {
        rk[i] = A;
        ER32(B, A, i++);
        rk[i] = A;
        ER32(C, A, i++);
    }
}
void SpeckEncrypt(u32 Pt[], u32 Ct[], u32 rk[])
{
    u32 i;
    Ct[0] = Pt[0];
    Ct[1] = Pt[1];
    for (i = 0; i < 26;)
        ER32(Ct[1], Ct[0], rk[i++]);
}
void SpeckDecrypt(u32 Pt[], u32 Ct[], u32 rk[])
{
    int i;
    Pt[0] = Ct[0];
    Pt[1] = Ct[1];
    for (i = 25; i >= 0;)
        DR32(Pt[1], Pt[0], rk[i--]);
}