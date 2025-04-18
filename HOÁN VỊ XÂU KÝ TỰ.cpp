#include<bits/stdc++.h>

using namespace std;

int n;
int used[20];
vector<string> res;
string current;

/*void solve(string s) {
    sort(s.begin(), s.end());
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << "\n";
}*/

void Try(string s, int n){
    if(current.size() == n){
        res.push_back(current);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            current.push_back(s[i]);
            used[i] = 1;
            Try(s, n);
            current.pop_back();
            used[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        res.clear();
        current = "";
        Try(s, s.size());
        memset(used, 0, sizeof(used));
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
