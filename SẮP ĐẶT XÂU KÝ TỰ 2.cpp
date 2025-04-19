#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int d; cin >> d;
        d--;
        string s; cin >> s;
        int cnt[256] = {0}; 
        for(char c : s){
            cnt[c]++;
        }
        int max_fre = 0;
        for(int i = 0; i < 256; i++){
            max_fre = max(cnt[i], max_fre);
        }
        if(max_fre <= (s.size() + d - 1) / d) cout << "1" << endl;
        else cout << "-1" << endl;
    }
}
