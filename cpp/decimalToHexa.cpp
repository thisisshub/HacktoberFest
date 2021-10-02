#include <bits/stdc++.h>

using namespace std;

string toHex(int num) {
    if (num == 0)
        return "0";

    u_int temp = num;
    string sol = "0123456789abcdef";
    string ans = "";
    while (temp > 0) {
        int r = temp % 16;
        ans = sol[r] + ans;
        temp = temp / 16;
    }
    return ans;
}

int main() {
    // your code goes here
    cout << toHex(26) << endl;
    return 0;
	// code contributed by chaitanyks
}
