#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int priority(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string infix_to_postfix(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.length(); i++){
        //if(isspace(s[i])) continue;
        if(isalpha(s[i])){
            res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top(); // đẩy toán hạng vào
                st.pop();
            }
            if(!st.empty()) st.pop(); // xoá dấu '('
        }
        else{
            while(!st.empty() && priority(st.top()) >= priority(s[i])){
                res += st.top();// So sánh độ ưu tiên với toán tử trên đỉnh stack.
                                //Nếu trên đỉnh stack có độ ưu tiên lớn hơn hoặc bằng, thì rút ra khỏi stack đưa vào kết quả.
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        if(st.top() != '(') res += st.top();
        st.pop();
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << infix_to_postfix(s) << endl;
    }
}
