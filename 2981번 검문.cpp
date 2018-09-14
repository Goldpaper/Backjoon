#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}

int main() {
    int N;
    int numArr[100];
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> numArr[i];
    }
    for(int i=0; i<N-1; i++) {
        numArr[i] = abs(numArr[i] - numArr[i+1]);
    }
    sort(numArr, numArr+N-1);
    
    int gcdNum = numArr[0];
    for(int i=1; i<N-1; i++) {
        gcdNum = gcd(numArr[i], gcdNum); 
    }

    vector<int> ans;
    for(int i=1;i*i<=gcdNum;i++)
        if (!(gcdNum % i)) {
            ans.push_back(i);
            if(i != gcdNum/i) ans.push_back(gcdNum/i);
        }
    sort(ans.begin(), ans.end());
    for (int& a : ans)
        if(a!= 1) printf("%d ", a);

    return 0;        
}
