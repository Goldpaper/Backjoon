#include <iostream>

#define Max 101

using namespace std;

int num;	//컴퓨터의 수
int result;	//결과 값 저장
int computer[Max][Max] = { 0, };
int visit[Max] = { 0, };

void dfs(int start) {
	visit[start] = 1;
	for (int i = 1; i <= num; i++) {
		if (!visit[i] && computer[start][i]) {
			result++;
			dfs(i);
		}
	}
}

int main() {
	int c_pair, temp1, temp2;
	cin >> num >> c_pair;
	while (c_pair--) {
		cin >> temp1 >> temp2;
		computer[temp1][temp2] = computer[temp2][temp1] = 1;
	}
	dfs(1);
	cout << result << endl;
}
