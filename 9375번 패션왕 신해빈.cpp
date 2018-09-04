#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int t, n;
	string tmp;
	cin >> t;
	while (t--) {
		map <string, int> cloth;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			cloth[type]++;
		}
		unsigned long long int result = 1;
		for (map<string, int>::iterator it = cloth.begin(); it != cloth.end(); it++) {
			result *= (unsigned long long int)(it->second + 1);
		}
		cout << result - 1 << endl;
	}
	return 0;
}