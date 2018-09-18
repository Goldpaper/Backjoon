#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int N, kim, imm;
    
    cin >> N >> kim >> imm;

    if(N < kim || N < imm) {
        return -1;
    }    
    while(kim != imm) {
        kim = (kim + 1) / 2;
        imm = (imm + 1) / 2;
        answer++;
    }
    cout << answer << "\n";
    return 0;
}