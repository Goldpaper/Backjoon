#include <iostream>
#define max(a,b) a > b ? a : b
using namespace std;

int main() {
	int n, tmp;
	int dp[100000] = { 0 };

	cin >> n;
	cin >> dp[0];
	int maxi = dp[0];
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		dp[i] = max(dp[i - 1] + tmp, tmp);
		maxi = max(dp[i], maxi);
	}
	cout << maxi << "\n";
	return 0;
}