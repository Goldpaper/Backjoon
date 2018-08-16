#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#define inf 100000000
using namespace std;

int main() {
	//정의
	ios::sync_with_stdio(false);
	struct spair { int x, y; bool operator< (const spair &a) const { if (this->x != a.x) { return this->x < a.x; } else { return this->y < a.y; } } };
	spair arr[100001];
	map<pair<int, int>, int> board;
	int N, result, dist;

	//입력처리 및 정렬
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + N);

	//라인 스위핑 방법 이용`
	board[{arr[0].y, arr[0].x}] = 1;
	board[{arr[1].y, arr[1].x}] = 1;
	result = (arr[0].x - arr[1].x) * (arr[0].x - arr[1].x) + (arr[0].y - arr[1].y) * (arr[0].y - arr[1].y);
	
	int j = 0;
	for (int i = 2; i < N; i++) {
		for (j; j < i; j++) {
			dist = arr[i].x - arr[j].x;
			if (dist * dist <= result)
				break;
			board.erase({ arr[j].y, arr[j].x });
		}
		int limit = sqrt(result);

		// y좌표를 봤을 때 현재 알고있는 최솟값 기준으로 답일 수 있는 영역 설정
		auto lo = board.lower_bound({ arr[i].y - limit, -inf });
		auto up = board.upper_bound({ arr[i].y + limit,  inf });

		// 그 영역 내에서 최솟값
		for (auto it = lo; it < up; it++) {
			int tmp = (it->first.second - arr[i].x) * (it->first.second - arr[i].x) + (it->first.first - arr[i].y) * (it->first.first - arr[i].y);
			result = result < tmp ? result : tmp;
			
		}
			
		// map에 추가
		board[{arr[i].y, arr[i].x}] = 1;
	}

	cout << result << "\n";
}
