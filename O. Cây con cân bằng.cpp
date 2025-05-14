#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
bool visited[100005];
int n, k;
vector<int> dist(100005);

void init(){
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void DFS(int u){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            dist[x] = dist[u] + 1;
            DFS(x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    dist[1] = 0;
    DFS(1);
    vector<int> lengths;
    for(int i = 1; i <= n; i++){
        lengths.push_back(dist[i]);
    }
    sort(lengths.begin(), lengths.end());
    long long res = 0;
    for(int i = lengths.size() - 1; i >= 0; i--){
        if(k > 0){
            k--;
            res += lengths[i];
        }
        else break;
    }
    cout << res << "\n";
}
