#include <bits/stdc++.h>
using namespace std;

int prime[1000007];
vector<int> v;
vector<int> res;
vector<vector<int>> ans;
int n, p, s, cnt;

void sieve_of_eratosthenes(){
    for(int i = 0; i <= 1000007; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= 1000007; i++){
        if(prime[i]){
            for(int j = i * i; j <= 1000007; j += i){
                prime[j] = 0;
            }
        }
    }
    v.clear();
    for(int i = 2; i <= 200; i++){
        if(prime[i]) v.push_back(i);
    }
}

void Try(int i, int pos, int sum){
    if(sum == s && res.size() == n){
        ans.push_back(res);
        return;
    }

    for(int j = pos; j < v.size(); j++){
        if(v[j] > p && sum + v[j] <= s){
            res.push_back(v[j]);
            Try(i + 1, j + 1, sum + v[j]);
            res.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    sieve_of_eratosthenes();
    while(t--){
        cin >> n >> p >> s;
        cnt = 0;
        res.clear();
        ans.clear();
        Try(0, 0, 0);
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            for(int x : ans[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
