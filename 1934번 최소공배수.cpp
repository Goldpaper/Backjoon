#include <iostream>

using namespace std;

int main() {
    int A, B, T, tmpA, tmpB, tmp;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        tmpA = A;
        tmpB = B;
        tmp = tmpA % tmpB;
        while(tmp != 0) {
            tmpA = tmpB;
            tmpB = tmp;
            tmp = tmpA % tmpB;
        }
        cout << A * B / tmpB << "\n";
    }
}