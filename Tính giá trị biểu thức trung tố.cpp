#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int priority(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

vector<string> infix_to_postfix(string s){
    stack<char> st;
    vector<string> res;
    for(int i = 0; i < s.length(); ++i){
        if (isdigit(s[i])) {
            string num = "";
            while (i < s.length() && isdigit(s[i])){
                num += s[i];
                i++;
            }
            i--; // vì vòng for sẽ tăng tiếp
            res.push_back(num);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res.push_back(string(1, st.top()));
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        else{ // toán tử
            while(!st.empty() && priority(st.top()) >= priority(s[i])){
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        res.push_back(string(1, st.top()));
        st.pop();
    }
    return res;
}

int evaluate_postfix(const vector<string>& postfix){
    stack<ll> st;
    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            st.push(stoll(token));
        } else {
            ll b = st.top(); st.pop();
            ll a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b); 
        }
    }
    return st.top();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        vector<string> postfix = infix_to_postfix(s);
        cout << evaluate_postfix(postfix) << '\n';
    }
}
