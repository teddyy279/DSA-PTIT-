#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1005][1005];
int visited[5005][5005];

struct Cell{
	int x, y, step;
};

int BFS(){
	queue<Cell> q;
	q.push({1, 1, 0});
	visited[1][1] = 1;
	while(!q.empty()){
		Cell current = q.front(); q.pop();
		if(current.x == m && current.y == n){
			return current.step;
		}
		int val = a[current.x][current.y];
		if(current.x + val <= m && !visited[current.x + val][current.y]){
			q.push({current.x + val, current.y, current.step + 1});
			visited[current.x + val][current.y] = 1;
		}
		if(current.y + val <= n && !visited[current.x][current.y + val]){
			q.push({current.x, current.y + val, current.step + 1});
			visited[current.x][current.y + val] = 1;
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		//int m, n; 
		memset(visited, 0, sizeof(visited));
		cin >> m >> n;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		cout << BFS() << '\n';
	}
}
