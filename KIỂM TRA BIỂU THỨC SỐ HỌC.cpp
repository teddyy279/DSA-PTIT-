/*Duyệt từng ký tự trong chuỗi.

Gặp dấu ) thì xem trong stack có toán tử (+ - * /) không.

Nếu không có toán tử → dấu ngoặc là dư thừa.

Nếu có toán tử → dấu ngoặc là cần thiết.
*/

#include<bits/stdc++.h>

using namespace std;

bool check(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')'){
            bool hasOperator = false;
            while(!st.empty() && st.top() != '('){
                char top = st.top(); st.pop();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    hasOperator = true;
                }
            }
            if(!hasOperator) return true;

            if(!st.empty()) st.pop(); // pop dấu '(';
        }
        else st.push(s[i]);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);
        if(check(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
