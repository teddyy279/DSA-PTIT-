#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
int n, m, s, t;

vector<vector<pair<int, int>>> adj;

void init() {
    cin >> n >> m >> s >> t;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w; 
        cin >> x >> y >> w;
        if (x < 1 || x > n || y < 1 || y > n) continue;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra(){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        ll distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(distance > dist[u]) continue;
        for(auto &e : adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    } 
    cout << dist[t] << "\n";  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    dijkstra();
    return 0;
}
