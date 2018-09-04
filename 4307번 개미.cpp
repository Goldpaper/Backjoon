#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t, n, length, ant;
    cin >> t;
    while(t--) {
        int mini = 0;
        int maxi = 0;
        cin >> length >> n;
        int mid = length / 2;
        while(n--) {
            cin >> ant;
            maxi = max({maxi, ant, length - ant}); 
            mini = max(mini, min(ant, length - ant));
        }
        cout << mini << " " << maxi << "\n";
    }
}