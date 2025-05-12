#include<bits/stdc++.h>

using namespace std;

int n, query;
int parent[100005];
int sz[100005];
unordered_map<int, int> colorCount[100005];
vector<int> v(100005);

void init(){
    cin >> n >> query;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        cin >> v[i];
        colorCount[i][v[i]] = 1;
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
    for(auto& [color, count] : colorCount[v]){
        colorCount[u][color] += count; 
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    while(query--){
        int command, x, y;
        cin >> command >> x >> y;
        if(command == 1){
            Union(x, y);
        }
        else{
            int root = Find(x);
            cout << colorCount[root][y] << "\n";
        }
    }
}
