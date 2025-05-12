#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<int> adj[100005];
bool visited[100005];
int price[100005];


void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u, int &min_cost){
   min_cost = min(min_cost, price[u]);
   visited[u] = true;
   for(int x : adj[u]){
    if(!visited[x]){
        DFS(x, min_cost);
    }
   }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    //ll min_cost = 0;
    ll total_cost = 0;
    for(int i = 1; i <= n; i++){
        int min_cost = 1e9;
        if(!visited[i]){
            DFS(i, min_cost);
            total_cost += min_cost;
        }
    }
    cout << total_cost << "\n";
}
