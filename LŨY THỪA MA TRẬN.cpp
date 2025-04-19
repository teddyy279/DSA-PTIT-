#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;

using ll = long long;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B, int n){
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] = (res[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll n, ll k){
    if(k == 0){
        vector<vector<ll>> I(n, vector<ll> (n, 0));
        for(int i = 0; i < n; i++) I[i][i] = 1;
        return I; // ma trận đơn vị trường hợp nhỏ nhất của ma trận;
    }
    
    if(k == 1) return A;

    vector<vector<ll>> half = matrixPow(A, n, k / 2);// chia nửa ma trận ra đó mũ  k / 2
    vector<vector<ll>> result = multiply(half, half, n); // tính ma trận lúc chia nửa ra;

    if(k % 2 == 1){
        result = multiply(result, A, n);
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vector<vector<ll>> a(n, vector<ll>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        vector<vector<ll>> result = matrixPow(a, n, k);
        for(int i = 0; i < result.size(); i++){
            for(int j = 0; j < result[i].size(); j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}
