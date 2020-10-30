#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i=0; i<s.length(); i++) {
            int c = s[s.length() - i - 1] - 'A' + 1;
            cout << pow(26, i) << endl;
            sum += c * int(round(pow(26, i)));
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("AB") << endl;
    return 0;
}
