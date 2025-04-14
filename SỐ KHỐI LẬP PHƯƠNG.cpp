#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(string a, string b){
    int idx = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[idx]){
            idx++;
            if(idx == b.size()) break;
        }
    }
    return idx == b.size();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        bool ok = false;
        string res;
        for(int i = 1; i <= 100; i++){
            string tmp = to_string(i * i * i);
            if(check(to_string(n), tmp)){
                res = tmp;
                ok = true;
                //break;
            }
        }
        if(!ok) cout << -1 << endl;
        else cout << res << endl;
    }
}
