#include <iostream>
#include <string>

using namespace std;

int main() {
    int dp[2501] = {0,};
    int chkP[2500][2500] = {0,};
    string str;
    int length;

    cin >> str;
    length = str.size();

    // 길이가 1인 팰린드롬
    for(int i=0; i < length; i++) {
        chkP[i][i] = 1;
    }

    // 길이가 2인 팰린드롬
    for(int i=0; i < length-1; i++) {
        if(str[i] == str[i+1])
            chkP[i][i+1] = 1;
    }

    // 길이가 3이상인 팰린드롬
    for(int i=2; i < length; i++) {
        for(int j=0; j < length-i+1; j++) {
            int k = i+j;
            if(str[j] == str[k] && chkP[j+1][k-1])
                chkP[j][k] = 1;
        }
    }
    
    // dp 탐색
    for(int i = 1; i <= length; i++) {
        dp[i] = i;
        for(int j = 1; j <= i; j++) {
            if(chkP[j-1][i-1]) {
                dp[i] = dp[i] < dp[j-1]+1 ? dp[i] : dp[j-1]+1;
            }
        }
    }
    cout << dp[length] << "\n";
}
