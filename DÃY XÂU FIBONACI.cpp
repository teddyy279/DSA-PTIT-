#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll F[93];

ll n, k;

void init(){
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= 92; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
}

char solve(ll n, ll k){
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k <= F[n - 2]) return solve(n - 2, k);
    else return solve(n - 1, k - F[n - 2]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    init();
    while(t--){
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
