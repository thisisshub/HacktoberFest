//prachi_balodia

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float n, r, t = 0;
    cin >> n;
    cin >> r;
    float volume = 1.32 * 3.142 * r * r * r;
    cout << "VOLUME OF SPHERE ";
    cout << setprecision(2) << volume << endl;
    return 0;
}