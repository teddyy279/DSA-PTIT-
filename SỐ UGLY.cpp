#include<bits/stdc++.h>

using namespace std;

void getUglyNumber(int n){
    vector<int> ugly(n);
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;
    for(int i = 1; i < n; i++){
        ugly[i] = min({next2, next3, next5});
        if(ugly[i] == next2){
            i2++;
            next2 = ugly[i2] * 2; 
        }
        if(ugly[i] == next3){
            i3++;
            next3 = ugly[i3] * 3;
        }
        if(ugly[i] == next5){
            i5++;
            next5 = ugly[i5] * 5;
        }
    }
    cout << ugly[n - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        getUglyNumber(n);
    }
}
