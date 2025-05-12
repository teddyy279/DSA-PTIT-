#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int parent_road[1000005], parent_rail[1000005];
int sz_road[1000005], sz_rail[1000005]; // Tách biệt sz cho road và rail

void init(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        parent_road[i] = parent_rail[i] = i;
        sz_road[i] = sz_rail[i] = 1; // Khởi tạo riêng
    }
}

int Find(int u, int parent[]){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u], parent);
}

bool Union(int u, int v, int parent[], int sz[]){
    u = Find(u, parent);
    v = Find(v, parent);
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
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        Union(x, y, parent_road, sz_road);
    }
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        Union(x, y, parent_rail, sz_rail);
    }
    map<pair<int, int>, int> mp; //lưu kết quả
    vector<pair<int, int>> roots(n + 1);
    for(int i = 1; i <= n; i++){
        roots[i] = {Find(i, parent_road), Find(i, parent_rail)}; //tìm thành phần liên thông đường bộ, sắt với đỉnh i
        mp[roots[i]]++;
    }
    for(int i = 1; i <= n; i++){
        cout << mp[roots[i]] << " ";
    }
}
