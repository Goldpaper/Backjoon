#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//정의
	struct spair { int start, end; bool operator< (const spair &a) const { if (this->end != a.end) { return this->end < a.end; } else { return this->start < a.start; } } };
	ios::sync_with_stdio(false);
	int N;
	spair arr[100000];
	int cnt = 0, endTime = 0;

	//입력처리 및 정렬
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end;
	}
	sort(arr, arr+N);

	//Greedy 알고리즘을 이용, 경우의 수 탐색
	for (int i = 0; i < N; i++) {
		if (endTime <= arr[i].start) {
			endTime = arr[i].end;
			cnt++;
		}
	}
	cout << cnt << "\n";
}
