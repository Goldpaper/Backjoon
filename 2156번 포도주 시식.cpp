#include <iostream>
#include <algorithm>

#define MAX 10001
//배열 크기 조심

using namespace std;

int main() {
    int n;
    int arr[MAX];
    int result[MAX];
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    result[0] = 0;
    result[1] = arr[1];
    result[2] = arr[1] + arr[2];

    for(int i=3; i<=n; i++) {
        result[i] = max(result[i-1], max(result[i-2] + arr[i], result[i-3] + arr[i-1] + arr[i]) );
    }
    cout << result[n] << endl;
}
