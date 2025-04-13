#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            v[i] = {x, y};
        }
        sort(v.begin(), v.end(), cmp);
        int dp[n + 1];
        for (int i = 0; i < n; i++) dp[i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(v[i].first > v[j].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        cout << *max_element(dp, dp + n) << '\n';
    }
}
