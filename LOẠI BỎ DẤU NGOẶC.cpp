// ý tưởng dùng BFS xong thử loại từng kí tự xong check xem nó đúng không, nếu đúng thì push vào res
#include<bits/stdc++.h>

using namespace std;

vector<string> res;

bool check(string s){
    int x = 0, y = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            x++; y++;
        }
        if(s[i] == ')') x--;
        if(x < 0) return false;
    }
    if(y == 0 && s.length() == 1) return false; // có 1 kí tự và nó không phải là dấu '(' hay dấu ')'
    return x == 0;
}

void BFS(string s){
    unordered_set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    bool found = false;
    while(!q.empty()){
        string current = q.front(); q.pop();
        if(check(current)){
            res.push_back(current);
            found = true;
        }
        if(found) continue; 
        /*chỗ này tìm được 1 thằng rồi thì continue luôn để không xét các thằng ở dưới nữa
        mà chỉ xét những thằng cùng level với nó vì đề bài yêu cầu tìm số bước ít nhất nếu
        có nhiều thằng cùng bước thì cho thằng đấy ra cả kết quả*/  
        for(int i = 0; i < current.length(); i++){
            if(current[i] == '(' || current[i] == ')'){
                string tmp = current.substr(0, i) + current.substr(i + 1, current.length());
                if(!visited.count(tmp)){
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        res.clear();
        BFS(s);
        if(res.empty()){
            cout << -1 << endl;
            continue;
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
