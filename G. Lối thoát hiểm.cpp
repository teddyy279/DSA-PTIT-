#include<bits/stdc++.h>

using namespace std;


int n, k;
vector<int> v;
vector<int> adj[100005];
bool visited[100005];
int m;
vector<int> dist(100005);

void init(){
    memset(visited, false, sizeof(false));
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void BFS(){
    queue<int> q;
    for(int i = 0; i < k; i++){
        q.push(v[i]);
        visited[v[i]] = true;
        dist[v[i]] = 0;
    }
    while(!q.empty()){
        int current = q.front(); q.pop();
        for(int x : adj[current]){
            if(!visited[x]){
                dist[x] = dist[current] + 1;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    BFS();
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}
