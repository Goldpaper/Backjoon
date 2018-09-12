#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int paper[50][50];
	int r1, c1, r2, c2;
	int tmp = 0;
	int maxi = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int x = i - r1;
			int y = j - c1;
			if (i - j < 0) {
				if (i + j < 0) {
					paper[x][y] = 4 * i * i + i + 1 - j;
				}
				else {
					paper[x][y] = 4 * j * j - 3 * j + 1 - i;
				}
			}
			else {
				if (i + j < 0) {
					paper[x][y] = 4 * j * j - j + 1 + i;
				}
				else {
					paper[x][y] = 4 * i * i + 3 * i + 1 + j;
				}
			}
			maxi = max(maxi, paper[x][y]);
		}
	}

	for (; maxi; maxi /= 10) tmp++;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			printf("%*d ", tmp, paper[i][j]);
		}
		cout << "\n";
	}
	return 0;
}