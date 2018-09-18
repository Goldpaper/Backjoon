#include <iostream>

using namespace std;

/* 문제 해결 방법 : 불판 전체를 뒤집자 */
int main() {
    int T, H, W;
    char revGrill[11][11]; //그릴을 뒤집어서 입력받음

    cin >> T;
    while(T--) {
        cin >> H >> W;
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                cin >> revGrill[i][j];
            }
        }

        for(int i=0; i<H; i++) {
            for(int j=W-1; j>=0; j--) {
                cout << revGrill[i][j];
            }
            cout << "\n";
        }
    }
}
