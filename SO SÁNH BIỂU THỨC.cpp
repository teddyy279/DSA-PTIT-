#include<bits/stdc++.h>

using namespace std;

string normalize(string s){
    stack<char> st1; // stack 1 lưu kết quả chuẩn hoá
    stack<char> st2; // stack2 quản lí dấu trước và sau ngoặc (lưu ý chỉ dấu liên quan đến ngoặc)
    s = "+" + s;
    st2.push('+');
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) st1.push(s[i]);
        if(s[i] == '+' or s[i] == '-'){
            if(st2.top() == '+'){
                st1.push(s[i]);
            }
            else{
                if(s[i] == '+') st1.push('-');
                else st1.push('+');
            }
        }
        if(s[i] == '(') st2.push(st1.top());
        else if(s[i] == ')') st2.pop();
    } 
    string res = "";
    while(!st1.empty()){
        res = st1.top() + res;
        st1.pop();
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        //getline(cin, s1);
        //getline(cin, s2);
        if(normalize(s1) == normalize(s2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
