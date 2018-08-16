#include <iostream>

using namespace std;

int main() {
	//정의
	ios::sync_with_stdio(false);
	int card[100];
	int N, M, tmp;
	int result = 0;

	//입력처리
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	
	//문제
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				tmp = card[i] + card[j] + card[k];
				if (tmp >= M) {
					if (tmp == M) {
						cout << tmp;
						return 0;
					}
					continue;
				}
				else if (result < tmp) {
					result = tmp;
				}
			}
		}
	}
	cout << result;
}
