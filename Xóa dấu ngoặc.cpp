#include<bits/stdc++.h>

using namespace std;

string s;
vector<pair<int, int>> brackets; //lưu vị trí của cặp ngoặc tương ứng
set<string> results;

void dfs(int idx, vector<bool> remove){
    if(idx == brackets.size()){
        string tmp;
        for(int i = 0; i < s.length(); i++){
            bool ok = true;
            for(int j = 0; j < brackets.size(); j++){
                if(remove[j] && (i == brackets[j].first || i == brackets[j].second)){
                    ok = false;
                    break;
                }
            }
            if(ok) tmp += s[i];
        }
        if(tmp != s) results.insert(tmp); // nếu tmp == s thì không khác gi chuỗi đầu nên cần có điều kiện này
        return;
    }

    dfs(idx + 1, remove); // không xoá cặp idx;

    //Xoá cặp idx
    remove[idx] = true;
    dfs(idx + 1, remove);
    remove[idx] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        else if(s[i] == ')'){
            int openIdx = st.top(); st.pop();
            brackets.push_back({openIdx, i});
        }
    }    

    vector<bool> remove(brackets.size(), false);
    dfs(0, remove);
    for(auto x : results){
        cout << x << endl;
    }
}
