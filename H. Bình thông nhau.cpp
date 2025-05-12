#include<bits/stdc++.h>

using namespace std;

int n, q;
vector<int> adj[10005];
int parent[10005];
int sz[10005];

void init(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
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
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    while(q--){
        int x, y, command;
        cin >> x >> y >> command;
        if(command == 1){
            Union(x, y);
        }
        else{
            if(Find(x) == Find(y)){
                cout << "Yes" << "\n";
            }
            else cout << "No" << "\n";
        }
    }
}
