#include<bits/stdc++.h>

using namespace std;

using ll = long long;
// dp[i] = dp[i - 1] * 10 + (i + 1) * digit[i]; 
//N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.
// 1 2 12 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll res = 0;
        ll current = 0;
        ll prev = 0;
        for(int i = 0; i < s.length(); i++){
            ll digit = s[i] - '0';
            current = prev * 10 + (i + 1) * digit;
            res = (res + current);
            prev = current;
        }
        cout << res << endl;
    }
}
