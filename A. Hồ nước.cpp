#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int grid[105][105];  
bool visited[105][105];


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int current_size = 0;

void DFS(int x, int y){
    visited[x][y] = true;
    current_size++;
    for(int k = 0; k < 4; k++){
        int i1 = x + dx[k];
        int j1 = y + dy[k];
        if(!visited[i1][j1] && i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && grid[i1][j1] == 1){
            DFS(i1, j1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        grid[x][y] = 1;
    }
    int maxLake = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                current_size = 0;
                DFS(i, j);
                maxLake = max(maxLake, current_size);
            }
        }
    }
    cout << maxLake << "\n";
}
