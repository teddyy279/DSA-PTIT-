#include<bits/stdc++.h>

/*Với N và K:

Nếu K == 2^(N-1) → chính là giá trị ở giữa, chính là N.

Nếu K < 2^(N-1) → nằm trong nửa trái, truy vấn tiếp với N-1 và K.

Nếu K > 2^(N-1) → nằm trong nửa phải, truy vấn tiếp với N-1 và K - 2^(N-1), vì nửa phải giống nửa trái.*/
using namespace std;

int FindValue(int n, int k){
    int mid = 1 << (n - 1); // 2 ^ (n - 1) 
    //mid  là độ dài từ đầu tới phần tử mid
    if(k == mid){
        return n;
    }
    if(k < mid){
        return FindValue(n - 1, k);
    }
    return FindValue(n - 1, k - mid);   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << FindValue(n, k);
    }
}
