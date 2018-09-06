#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int dp[1001][1001] = { 0 };
	string str1, str2;
	string result = "";
	cin >> str1;
	cin >> str2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[len1][len2] << "\n";

	while (dp[len1][len2] != 0) {
		if (dp[len1][len2] == dp[len1][len2 - 1]) {
			len2--;
		}
		else if (dp[len1][len2] == dp[len1 - 1][len2]) {
			len1--;
		}
		else {
			result += str1[len1-1];
			len1--;
			len2--;
		}
	}

	for (int i = result.size(); i > 0; i--) {
		cout << result[i - 1];
	}

	return 0;
}