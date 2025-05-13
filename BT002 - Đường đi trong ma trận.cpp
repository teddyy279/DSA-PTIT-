#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[105][105], d[105][105];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dijkstra(int x1, int y1, int x2, int y2){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = 1e9;
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({a[x1][y1], {x1, y1}});
    d[x1][y1] = a[x1][y1];
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int distance = it.first, i = it.second.first, j = it.second.second;
        if(i == x2 && j == y2){
            cout << distance << endl;
            return;
        }
        for(int k = 0; k < 4; k++){
            int i1 = dx[k] + i;
            int j1 = dy[k] + j;
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
                if(d[i1][j1] > d[i][j] + a[i1][j1]){
                    d[i1][j1] = d[i][j] + a[i1][j1];
                    pq.push({d[i1][j1], {i1, j1}});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        dijkstra(x1, y1, x2, y2);
    }
    return 0;
}
