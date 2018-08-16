#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	//ios::sync_with_stdio(false);
	int M[100000];	//#define MAX 100000
	int N, temp1;

	//정수 세팅
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &M[i]);
	}
	sort(M, M + N);

	// 각각의 테스트 케이스 점검
	int T, chk, start, mid, end;
	scanf("%d", &T);
	while (T--) {
		start = 0, end = N - 1, mid = (start + end) / 2;
		scanf("%d", &chk);

		//이분 탐색
		while ((end - start) >= 0) {
			if (chk == M[mid]) {
				printf("1\n");
				break;
			}
			else if (chk < M[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			mid = (start + end) / 2;
		}
		if(chk != M[mid])
			printf("0\n");
	}
}