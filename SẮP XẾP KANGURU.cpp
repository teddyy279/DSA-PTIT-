#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> kangurus(n);
        for(int i = 0; i < n; i++) cin >> kangurus[i];
        sort(kangurus.begin(), kangurus.end());
        int i = 0, j = n / 2;
        int cnt = 0;
        while(i < n / 2 &&  j < n){
            if(kangurus[j] >= 2 * kangurus[i]){
                i++; j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        //cnt là số cặp ghép thành công => số con kanguru thấy ít nhất = n - cnt
        cout << n - cnt << endl;
    }   
}
