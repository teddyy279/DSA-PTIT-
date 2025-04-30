#include<bits/stdc++.h>

using namespace std;

int n, m;
int sz[100005];
int parent[100005];

void init(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v])  swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        Union(u, v);
    }
    int root1 = Find(1);
    int currentSize = sz[root1];
    int maxExtra = 0;
    for(int i = 1; i <= n; i++){
        int root = Find(i);
        if(root != root1){
            maxExtra = max(maxExtra, sz[root]);
        }
    }
    cout << currentSize + maxExtra << endl;
}
