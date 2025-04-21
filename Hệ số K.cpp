#include<bits/stdc++.h>

using namespace std;

string solve(string a, string b, int k){
    while(a.length() < b.length()){
        a = "0" + a;
    }
    while(b.length() < a.length()){
        b = "0" + b;
    }
    int remainder = 0;
    string res = "";
    for(int i = a.length() - 1; i >= 0; i--){
        int digit = (a[i] - '0') + (b[i] - '0') + remainder;
        res = to_string(digit % k) + res;
        remainder = digit / k;
    }
    if(remainder > 0) res = to_string(remainder) + res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int k;
        string a, b; cin >> k >> a >> b;
        cout << solve(a, b, k) << endl;
    }
}
