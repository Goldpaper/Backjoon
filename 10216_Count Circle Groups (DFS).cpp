#include <iostream>
#include <vector>
#define Max 5001

using namespace std;
typedef pair<pair<int, int>, pair<int, int>> pair4;

int N, group_num;	//그룹 갯수
vector<pair4> enemy;	//순서대로 x, y, R, visit여부를 저장

//두 지점이 통신 가능한지를 비교 (가능하면 1)
int compare(int a, int b) {
	int r = enemy[a].second.first + enemy[b].second.first;
	int x = enemy[a].first.first - enemy[b].first.first;
	int y = enemy[a].first.second - enemy[b].first.second;
	return (((x * x) + (y * y)) <= (r * r)) ? true : false;
}

void dfs(int k) {
	//(실수)양방향으로 확인하기!
	for (int i = 0; i < N; i++) {
		if (enemy[i].second.second) {
			continue;
		}
		//통신 가능 하다면
		if (compare(i, k)) {
			enemy[i].second.second = 1;
			enemy[k].second.second = 1;
			dfs(i);
		}
	}
}

int main() {
	int T, x, y, R;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> R;
			enemy.push_back(make_pair(make_pair(x, y), make_pair(R, 0)));
		}

		group_num = 0;
		for (int i = 0; i < N; i++) {
			if (!enemy[i].second.second) {	//방문하지 않았다면
				enemy[i].second.second = 1;
				dfs(i);
				group_num++;
			}
		}
		cout << group_num << endl;
		enemy.clear();
	}
}
