#include <iostream>

using namespace std;

int main() {
	unsigned long long int result;
	int n, k;
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0) {
			return 0;
		}

		if (k > n - k)
			k = n - k;

		result = 1;
		for (int i = 1; i <= k; i++) {
			result = result * (n - k + i) / i;
		}

		cout << result << endl;
	}
}