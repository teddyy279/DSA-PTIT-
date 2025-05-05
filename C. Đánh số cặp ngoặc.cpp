#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore(); 
    while(t--){
        string s;
        getline(cin, s);
        stack<int> st;
        vector<int> ans;
        int counter = 1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(counter);
                ans.push_back(counter);
                counter++;
            }
            else if(s[i] == ')'){
                int id = st.top(); st.pop();
                ans.push_back(id);
            }
        }
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
}
