#include<bits/stdc++.h>

using namespace std;

int solve(string s){
    stack<int> st;
    st.push(-1);
    int max_len = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()) st.push(i);
            else{
                max_len = max(max_len, i - st.top());
            }
        }
    }
    return max_len;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}
