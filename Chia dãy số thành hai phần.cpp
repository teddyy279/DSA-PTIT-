#include<bits/stdc++.h>

using namespace std;
using ll = long long;
//bài này có s1 + s2 = s (sao cho s1 s2 gần s/2 nhất (tại vì thế thì s sẽ max)) => để s max <=> s1 * (s - s1) || s2 * (s - s2)

//Cách 1(8 test)
/*long long maxProductPartition(vector<int> v){
    ll total_sum = 0;
    for(int i = 0; i < v.size(); i++){
        total_sum += v[i];
    }
    ll half_sum = total_sum / 2;

    vector<ll> dp(half_sum + 1, false);
    dp[0] = true;

    for(int i = 0; i < v.size(); i++){
        for(int j = half_sum; j >= v[i]; j--){
            if(dp[j - v[i]]){
                dp[j] = true;
            }
        }
    }

    ll max_sum = 0;
    for(int i = half_sum; i >= 0; i--){
        if(dp[i]){
            max_sum = i;
            break;
        }
    }
    return (ll) max_sum * (total_sum - max_sum);
} */

// C2(AC)
long long maxProductPartition(vector<int> v){
    ll total_sum = 0;
    for(int i = 0; i < v.size(); i++){
        total_sum += v[i];
    }
    ll half_sum = total_sum / 2;

    bitset<100001> dp;
    dp[0] = 1;

    for(int i = 0; i < v.size(); i++){
        dp |= (dp << v[i]);
    }

    ll max_sum = 0;
    for(int i = half_sum; i >= 0; i--){
        if(dp[i]){
            max_sum = i;
            break;
        }
    }
    return (ll) max_sum * (total_sum - max_sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        cout << maxProductPartition(v) << endl;
    }
}
