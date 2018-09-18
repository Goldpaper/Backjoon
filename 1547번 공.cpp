#include <iostream>

using namespace std;

int main() {
    int ball = 1;
    int M, X, Y;
    cin >> M;
    while(M--) {
        cin >> X >> Y;
        if(X == ball) {
            ball = Y;
        }
        else if(Y == ball) {
            ball = X;
        }
    }
    cout << ball << "\n";
    return 0;
}