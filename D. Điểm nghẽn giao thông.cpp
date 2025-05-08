#include<bits/stdc++.h>

using namespace std;

int n, m, x, y;
vector<vector<int>> res;
vector<int> adj[1005];
bool visited[1005];
//vector<int> path;

void init(){
    cin >> n >> m >> x >> y;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
}

void DFS(int u, int banned){
    visited[u] = true;
    for(int x : adj[u]){
        if(x == banned) continue;
        if(!visited[x]){
            DFS(x, banned);
        }
    }
}

int countCriticalNodes(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        if(i == x || i == y) continue;
        visited[i] = true;
        DFS(x, i);
        if(!visited[y]) cnt++; 
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        init();
        cout << countCriticalNodes() << endl;
    }
}
