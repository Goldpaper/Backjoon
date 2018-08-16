#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int board[100][100];
	long long dp[100][100] = { 0, };
	int N, jump;

	cin >> N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			jump = board[i][j];
			if ((i + jump) < N && i< N-1 ) {
				dp[i + jump][j] += dp[i][j];
			}
			if ((j + jump) < N && j < N-1 ) {
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1];
	cin >> N;
}
