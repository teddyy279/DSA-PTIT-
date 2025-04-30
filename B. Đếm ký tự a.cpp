#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F[46];       // F[i] = độ dài xâu F[i]
ll cntA[46];    // cntA[i] = số ký tự 'a' trong F[i]

void init(){
    F[0] = 1; cntA[0] = 1;  // F[0] = "a"
    F[1] = 1; cntA[1] = 0;  // F[1] = "b"
    for(int i = 2; i <= 45; i++){
        F[i] = F[i - 1] + F[i - 2];
        cntA[i] = cntA[i - 1] + cntA[i - 2];
    }
}

ll countA(int n, ll k){
    if(k == 0) return 0;
    if(n == 0) return 1;  // F[0] = "a"
    if(n == 1) return 0;  // F[1] = "b"
    if(k <= F[n - 1]) return countA(n - 1, k);
    else return cntA[n - 1] + countA(n - 2, k - F[n - 1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin >> t;
    while(t--){
        int n; ll k;
        cin >> n >> k;
        cout << countA(n, k) << '\n';
    }
    return 0;
}
