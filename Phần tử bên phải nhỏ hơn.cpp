#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> v){
    int n = v.size();
    vector<int> nextGreater(n, -1);
    vector<int> nextSmaller(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && v[i] > v[st.top()]){
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    st = stack<int>(); // gán lại stack rỗng
    for(int i = 0; i < n; i++){
        while(!st.empty() && v[i] < v[st.top()]){
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    for(int i = 0; i < n; i++){
        int greaterIndex = nextGreater[i];
        if(greaterIndex != -1){
            int smallerIndex = nextSmaller[greaterIndex];
            if(smallerIndex != -1) cout << v[smallerIndex] << " ";
            else cout << -1 << " ";
        }
        else cout << -1 << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        solve(v);
    }
}
