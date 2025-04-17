/*Ý tưởng:
Với mỗi vị trí i trong chuỗi:

Nếu s[i-1] là ký tự từ '1' đến '9', thì có thể giải mã 1 ký tự → cộng dp[i-1].

Nếu s[i-2]s[i-1] (tức là hai ký tự trước đó) tạo thành số từ 10 đến 26, thì có thể giải mã thành 1 chữ cái → cộng dp[i-2].*/

// substr(2, 3) lấy từ vị trí 2 của string và lấy 3 phần tử

#include<bits/stdc++.h>

using namespace std;

int countWays(string s){
    //n = s.length();
    if(s[0] == '0') return 0;
    vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= s.length(); i++){
        if(s[i - 1] != '0'){
            dp[i] += dp[i - 1];
        }
        int two_digit = stoi(s.substr(i - 2, 2));
        if(two_digit >= 10 && two_digit <= 26){
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length()];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << countWays(s) << endl;
    }
}
