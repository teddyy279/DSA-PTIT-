#include<bits/stdc++.h>

using namespace std;

int n;
int adj[105][105];
bool visited[105];

void DFS(int u){
    visited[u] = true;
    for(int v = 1; v <= n; v++){
        if(adj[u][v] && !visited[v]){
            DFS(v);
        }
    }
}

int count_components(){
    int count = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count++;
            DFS(i);
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j];
        }
    }
    int bridges = 0;
    int original_components = count_components(); // số lượng thành phần liên thông ban đầu
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(adj[i][j]){
                adj[i][j] = adj[j][i] = 0; // xoá cạnh
                int new_components = count_components();
                if (new_components > original_components)
                    bridges++;
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    cout << bridges << "\n";
}
