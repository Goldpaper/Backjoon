#include <iostream>

using namespace std;

int main() {
    long long int A, B, tmpA, tmpB, tmp;
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