#include<bits/stdc++.h>
using namespace std;

int k, m, n;
unordered_set<string> dict;
char grid[105][105];
bool visited[105][105];
vector<string> found;
int max_len;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void flood_fill(int i, int j, string current){
    if(dict.count(current)) found.push_back(current);
    visited[i][j] = true;

    for(int k = 0; k < 8; k++){
        int i1 = dx[k] + i;
        int j1 = dy[k] + j;
        if(i1 >= 0 && j1 >= 0 && i1 < m && j1 < n && !visited[i1][j1]){
            flood_fill(i1, j1, current + grid[i1][j1]);
        }
    }

    visited[i][j] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        cin >> k >> m >> n;
        dict.clear();
        found.clear();
        //max_len = 0;

        for(int i = 0; i < k; i++){
            string word; cin >> word;
            dict.insert(word);
            //max_len = max(max_len, (int)word.size());
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                memset(visited, false, sizeof(visited));
                flood_fill(i, j, string(1, grid[i][j]));
            }
        }
        if(found.empty()){
            cout << -1 << endl;
        } else {
            for(auto &word : found){
                cout << word << " ";
            }
            cout << endl;
        }
    }
}
