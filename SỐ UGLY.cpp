#include<bits/stdc++.h>

using namespace std;

bool isUgly(int n){
    if(n <= 0) return false;
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    return n == 1;
}

int FindNthUgly(int n){
    int cnt = 0;
    int num = 1;
    while(true){
        if(isUgly(num)){
            cnt++;
            if(cnt == n) return num;
        }
        num++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << FindNthUgly(n) << endl;
    }
}
