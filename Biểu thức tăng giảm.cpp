#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    stack<int> st;
    int num = 1;
    string res = "";
    for(int i = 0; i <= s.length(); i++){
        st.push(num++);
        if(i == s.length() || s[i] == 'I'){ //Nếu là kí tự I hoặc tới cuối chuỗi thì xả stack
            while(!st.empty()){
                res += to_string(st.top());
                st.pop();
            }
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }
}
