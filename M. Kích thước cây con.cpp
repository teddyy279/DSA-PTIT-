#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
vector<int> adj[MAXN];
bool visited[MAXN];
int sz[MAXN]; 

void dfs(int u){
    visited[u] = true;
    sz[u] = 1; 
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);           
            sz[u] += sz[v];    
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << sz[i] << " ";
    }
}
