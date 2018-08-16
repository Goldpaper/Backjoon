#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int M[100000] = { 0, };	//#define MAX 100000
	int N, temp1;

	//정수 세팅 (카운팅정렬 기법 응용)
	cin >> N;
	while (N--) {
		cin >> temp1;
		M[temp1] = 1;
	}
	
	//여부 확인 (T : testcase)
	int T, chk;
	cin >> T;
	while (T--) {
		cin >> chk;
		cout << M[chk] << "\n";
	}
}