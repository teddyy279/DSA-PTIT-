#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
int in_degree[1005], out_degree[1005];
int visited[1005];

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_degree[y]++, out_degree[x]++;
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            visited[x] = true;
            DFS(x);
        }
    }
}

int tplt(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }   
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            in_degree[i] = out_degree[i] = 0;
        }
        nhap();
        bool check = true;
        for(int i = 1 ; i <= n; i++){
            if(in_degree[i] != out_degree[i]){
                check = false;
            }
        }
        int tmp = tplt();
        if(tmp == 1 && check){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}
