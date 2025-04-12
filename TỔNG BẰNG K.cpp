#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < v.size(); i++) cin >> v[i];
        int dp[k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(i >= v[j]){
                    dp[i] += dp[i - v[j]];
                }
                dp[i] %= mod;
            }
        }
        cout << dp[k] << endl;
    }
}
