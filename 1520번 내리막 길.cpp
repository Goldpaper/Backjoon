/*
완전탐색이나 BFS로는 해결불가. DFS를 이용한 DP로 해결해야 함
*/

#include <iostream>
#include <algorithm>

#define MAX 502
using namespace std;

int M, N;
int maps[MAX][MAX];
int visited[MAX][MAX];
int chk_x[4] = {1, -1, 0, 0};
int chk_y[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if(x == 1 && y == 1) {
        return 1;
    }
    if(visited[y][x]) {
        return visited[x][y];
    }
    for(int i=0; i<4; i++) {
        int tmp_x = x + chk_x[i];
        int tmp_y = y + chk_y[i];
        if (maps[tmp_x][tmp_y] > maps[x][y] && tmp_x > 0 && tmp_x <= N && tmp_y > 0 && tmp_y <= M){
            visited[x][y] += dfs(tmp_x, tmp_y);
        }
    }
    return visited[x][y];
}

int main() {
    //memset(maps, 0, sizeof(maps));

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> maps[M][N];
        }
    }
    cout << dfs(N,M) << "\n";
    
}
