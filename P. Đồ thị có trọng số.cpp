#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int dist[1005][1005];

void solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = (i == j) ? 0 : 1e9;
        }
    }
    while(m--){
        int x, y, w; cin >> x >> y >> w;
        dist[x][y] = min(dist[x][y], w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        if(dist[x][y] == 1e9) cout << "-1\n";
        else cout << dist[x][y] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
