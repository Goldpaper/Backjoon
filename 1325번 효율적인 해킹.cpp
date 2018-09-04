/*
사이클이 생길 수 있다.
무한반복을 방지하자
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	vector<short> comp[10001];
	queue<short> q;
	int N, M;
	short result[10001] = { 0 };
	short visit[10001] = { 0 };
	int max = 0;

	cin >> N >> M;
	while (M--) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		comp[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) {
			continue;
		}
		q.push(i);
		int cnt = 0;
		while (!q.empty()) {
			vector<short> tmpVec = comp[q.front()];
			q.pop();
			while (!tmpVec.empty()) {
				q.push(tmpVec.back());
				visit[tmpVec.back()] = 1;
				tmpVec.pop_back();
			}
			cnt++;
		}
		result[i] = cnt;
		max = max < cnt ? cnt : max;
	}
	for (int i = 1; i <= 10000; i++) {
		if (max == result[i]) {
			cout << i << " ";
		}
	}
}