#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

int main() {
    int N, gcdNum;
    int R[100] = {0};
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> R[i];
    }

    for(int i=1; i<N; i++) {
        if(R[i] > R[0]) {
            gcdNum = gcd(R[i], R[0]);
        }
        else {
            gcdNum = gcd(R[0], R[i]);
        }
        cout << R[0] / gcdNum << "/" << R[i] / gcdNum << "\n";
    }
    return 0;
}