#include<bits/stdc++.h>

using namespace std;

int is_adjacent(const string& a, const string& b){
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            diff++;
            if(diff > 1) return 0;
        }
    }
    return diff == 1;
}


void BFS(string s, string t, vector<string> &words){
    //if(s == t) return 0;
    queue<pair<string, int>> q;
    q.push({s, 1});
    unordered_set<string> se;
    se.insert(s);
    while(!q.empty()){
        pair<string, int> current = q.front(); q.pop();
        if(current.first == t){
            cout << current.second << endl;
            return;
        }
        for(int i = 0; i < words.size(); i++){
            if(!se.count(words[i]) && is_adjacent(current.first, words[i])){
                q.push({words[i], current.second + 1});
                se.insert(words[i]);
            }
        }
    }
    //return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase; cin >> testcase;
    while(testcase--){
        int n; string s, t;
        cin >> n >> s >> t;
        vector<string> words;
        while(n--){
            string tmp; cin >> tmp;
            words.push_back(tmp);
        }
        if(s == t){
            cout << 1 << endl;
            continue;
        }
        BFS(s, t, words);
    }
}
