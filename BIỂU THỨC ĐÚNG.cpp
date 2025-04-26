#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    stack<char> st;
    int countLeft = 0, countRight = 0;
    int imbalance = 0, countSwap = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '['){
            countLeft++;
            if(imbalance > 0){
                countSwap += imbalance;
                imbalance--;
            }
        }
        else{
            countRight++;
            imbalance = countRight - countLeft;
        }
    }
    cout << countSwap << endl;
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
