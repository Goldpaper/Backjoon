#include <iostream>
#include <algorithm>
#include <vector>

#define Max 26

using namespace std;

char map[Max][Max] = { 0, };
int visit[Max][Max] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, cnt = 0;

void dfs(int i, int j) {
	visit[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (0 <= x && x < N && 0 <= y && y < N) {
			if (map[x][y] == '1' && !visit[x][y]) {
				cnt++;
				dfs(x, y);
			}
		}
	}
}

int main() {
	int danzi_num = 0;
	vector<int> house_num;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !visit[i][j]) {
				danzi_num++;
				cnt = 1;
				dfs(i, j);
				house_num.push_back(cnt);
			}				
		}
	}
	sort(house_num.begin(), house_num.end());

	cout << danzi_num << endl;
	
	/* (범위기반 for문 : 구버전 컴파일러에서 '출력 초과'가 나타남)
	for (int i: house_num) {
		cout << i << endl;
	} */

	for (int i = 0; i < house_num.size(); i++) {
		cout << house_num[i] << endl;
	}
}
