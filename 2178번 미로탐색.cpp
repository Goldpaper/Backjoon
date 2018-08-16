//test
#include <iostream>
#include <queue>

#define Max 100

using namespace std;

int main() {
	int M, N, x, y, tx, ty;
	char tmp[Max];
	int maze[Max][Max] = { 0, };
	int result = 0;
	queue<pair<int, int>> q;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			maze[i][j] = tmp[j] - 48;
		}
	}
	maze[0][0] = 0;

	q.push(make_pair(0, 0));
	int side[4] = { 1, 0, -1, 0 };
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		if (maze[x][y] == 2 + result)
			result++;

		for (int i = 0; i < 4; i++) {
			tx = x - side[i];
			ty = y - side[3 - i];
			if (0 <= tx && tx < N && 0 <= ty && ty < M) {
				if (maze[tx][ty] == 1) {
					maze[tx][ty] = 2 + result;
					q.push(make_pair(tx, ty));
				}
			}
		}
		q.pop();
	}

	cout << maze[N-1][M-1] << endl;
	cin >> N;
}
