#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x, y, z; cin >> x >> y >> z;
        vector<int> dp(n + 1, 1e9);
        dp[1] = x; // kí tự đầu tiên thì chỉ thì có thể insert
        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i], dp[i - 1] + x);
            if(i % 2 == 0){
                dp[i] = min(dp[i], dp[i / 2] + z);
            }
            else{
                dp[i] = min(dp[i], dp[(i + 1) / 2] + z + y);
            }
        }
        cout << dp[n] << endl;
    }
}
