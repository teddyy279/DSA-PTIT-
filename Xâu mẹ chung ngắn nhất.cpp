#include<bits/stdc++.h>

using namespace std;

//Độ dài của chuỗi mẹ chung ngắn nhất = len(A) + len(B) - LCS(A, B)(longest commom supersequence )
int dp[505][505];

int LCS(string a, string b){
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[a.size() - 1][b.size() - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        a = "+" + a;
        b = "-" + b;
        cout << a.length() + b.length() - LCS(a, b) - 2 << endl; // trừ đi 2 vì thêm 2 kí tự
    }
}
