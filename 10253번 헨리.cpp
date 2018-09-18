#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    int T, a, b, gcdNum, tmp;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        while(a != 1) {
            int tmp = b / a + 1;
            a = a * tmp - b;
            b = b * tmp;

            gcdNum = gcd(a,b);
            a /= gcdNum;
            b /= gcdNum; 
        }
            cout << b << endl;

    }
    return 0;
}
