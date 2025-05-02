    #include<bits/stdc++.h>

    using namespace std;

    int n, m;
    vector<int> adj[10005];
    vector<int> topo;
    vector<bool> visited(10005, false);

    void init(){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
    }

    void DFS_topo(int u){
        visited[u] = true;
        //topo.push_back
        for(int x : adj[u]){
            if(!visited[x]){
                DFS_topo(x);
            }
        }
        topo.push_back(u);
    }

    void DFS_mark(int u){
        visited[u] = true;
        for(int x : adj[u]){
            if(!visited[x]){
                DFS_mark(x);
            }
        }
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        init();
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                DFS_topo(i);
            }
        }

        reverse(topo.begin(), topo.end());
        fill(visited.begin(), visited.end(), false);
        int res = 0;
        for(int x : topo){
            if(!visited[x]){
                res++;
                DFS_mark(x);
            }
        }
        cout << res << "\n";
    }
