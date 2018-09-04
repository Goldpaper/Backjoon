/*
사이클이 생길 수 있다.
무한반복을 방지하자
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<short> comp[10001];
short result[10001] = { 0 };
short visit[10001] = { 0 };

int dfs(int x, int y) {
	if (visit[x] == y) return 0;
	int answer = 1;
	visit[x] = y;
	for (auto it : comp[x]) {
		answer += dfs(it, y);
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	while (M--) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		comp[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= N; i++) {
		result[i] = dfs(i, i);
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (max == result[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}