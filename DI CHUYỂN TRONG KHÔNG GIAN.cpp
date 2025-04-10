#include<bits/stdc++.h>

using namespace std;

struct Node{
    int z, x, y;
};

int a, b, c;

char maze[35][35][35];
int visited[35][35][35];
int dist[35][35][35];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void BFS(Node start, Node end){
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    queue<Node> q;
    q.push({start});
    visited[start.z][start.x][start.y] = 1;
    dist[start.z][start.x][start.y] = 0;
    while(!q.empty()){
        Node front = q.front(); q.pop();
        if(front.z == end.z && front.x == end.x && front.y == end.y){
            return;
        }
        for(int k = 0; k < 6; k++){
            int x1 = dx[k] + front.x;
            int y1 = dy[k] + front.y;
            int z1 = dz[k] + front.z;
            if(x1 >= 0 && y1 >= 0 && z1 >= 0 && x1 < b && y1 < c && z1 < a && maze[z1][x1][y1] != '#' && visited[z1][x1][y1] == 0){
                q.push({z1, x1, y1});
                visited[z1][x1][y1] = 1;
                dist[z1][x1][y1] = dist[front.z][front.x][front.y] + 1;    
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> c;
        Node start, end;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                string line; cin >> line;
                for(int k = 0; k < c; k++){
                    maze[i][j][k] = line[k];
                    if(maze[i][j][k] == 'S'){
                        start.x = j, start.y = k; start.z = i;
                    }
                    if(maze[i][j][k] == 'E'){
                        end.x = j, end.y = k, end.z = i;
                    }
                }
            }
        }
        BFS(start, end);
        if(visited[end.z][end.x][end.y] != 0) cout << dist[end.z][end.x][end.y] << endl;
        else cout << -1 << endl; 
    }
}
