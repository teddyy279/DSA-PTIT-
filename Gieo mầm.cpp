#include<bits/stdc++.h>

using namespace std;

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[505][505], b[505][505];
int cnt = -1;

void BFS(){
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        //pair<int, int> front = q.front();
        int size = q.size();
        cnt++;
        while(size--){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int i1 = x + dx[k];
                int j1 = y + dy[k];
                if(i1 >= 0 && j1 >= 0 && i1 < n && j1 < m && a[i1][j1] == 1){
                    q.push({i1, j1});
                    a[i1][j1] = 2;
                }
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    BFS();
    int check = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                check = 0;
            }
        }
    }
    if(check) cout << cnt << endl;
    else cout << -1 << endl;
    }
}
