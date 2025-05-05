#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int prime[MAX + 1];
int mp[MAX + 1]; 
long long prefix_sum[MAX + 1]; 

void sieve_eratosthenes(){
    for(int i = 0; i <= MAX; i++){
        prime[i] = 1;
        //mp[i] = i; 
    }
    prime[0] = prime[1] = 0;
    mp[0] = 0;
    mp[1] = 0;
    for(int i = 2; i <= MAX; i++){
        if(prime[i]){
            for(int j = i * 2; j <= MAX; j += i){
                prime[j] = 0;
                mp[j] = i; 
            }
            mp[i] = i;
        }
    }
    prefix_sum[0] = 0;
    prefix_sum[1] = 0;
    for(int i = 2; i <= MAX; i++){
        prefix_sum[i] = prefix_sum[i - 1] + mp[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve_eratosthenes();
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << '\n';
    }
    return 0;
}
