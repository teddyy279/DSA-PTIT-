#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[105];
vector<int> res;
bool found = false;

void Try(int pos, int sum){
    if(sum == x){
        cout << "[";
        for(int i = 0; i < res.size(); i++){
            cout << res[i];
            if(i < res.size() - 1) cout << " ";
        }
        cout << "]";
        found = true;
        return;
    }

    for(int j = pos; j < n; j++){
        if(sum + a[j] <= x){
            res.push_back(a[j]);
            Try(j, sum + a[j]); 
            res.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);  
        res.clear();
        found = false;
        Try(0, 0);
        if(!found) cout << -1;
        //cout << " ";
        cout << "\n";
    }
}
