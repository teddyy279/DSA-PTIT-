#include<bits/stdc++.h>

using namespace std;

int n, m;
int parent[1005];
int sz[1005];
pair<int, int> coords[1005];

struct edge{
    int x, y;
    long double dist;
};

void init() {
    cin >> n >> m;
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

long double calcDist(int i, int j){
    long long dx = coords[i].first - coords[j].first;
    long long dy = coords[i].second - coords[j].second;
    return sqrtl(dx * dx + dy * dy);
}

bool cmp(edge a, edge b){
    return a.dist < b.dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        coords[i].first = x;
        coords[i].second = y;
    }
    int initial_edges = 0;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if (Union(x, y)) {
            initial_edges++;
        }
    }
    vector<edge> edges;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            edges.push_back({i, j, calcDist(i, j)});
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    long double result = 0;
    int cnt = initial_edges;
    for(auto &E : edges){
        if (cnt >= n - 1) break;
        if (Union(E.x, E.y)){
            result += E.dist;
            cnt++;
        }
    }
    cout << fixed << setprecision(2) << result << "\n";
    return 0;
}
