#include<bits/stdc++.h>

using namespace std;

int n;

int parent[1005];
int sz[1005];
vector<pair<int, int>> edges;


void nhap(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        edges.push_back({x, y});
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]){
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        init();
        pair<int, int> res;
        for(auto e : edges){
            if(!Union(e.first, e.second)){
                res = {e.first, e.second};
            }
        }
        cout << res.first << " " << res.second << endl;
        edges.clear();
    }
}
