#include<bits/stdc++.h>
 
using namespace std;

vector<int> a(505);
int n;
int s = 0;
int check = 0;

void Try(int sum, int pos){
    if(sum == s){
        check = 1;
        return;
    }
    for(int i = pos; i < n; i++){
        if(sum + a[i] <= s){
            Try(sum + a[i], i + 1);
        }
        if(check) return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n;
        s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        if(s % 2 != 0){
            cout << "NO" << endl;
            continue;
        }
        s /= 2;
        Try(0, 0);
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
