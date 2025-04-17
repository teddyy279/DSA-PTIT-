#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ll gcd(ll a, ll b) {
//    return b ? gcd(b, a % b) : a;
//}

void decompose_fraction(ll q, ll p) {
    vector<ll> result;
    while (q != 0) {
        if (p % q == 0) {
            result.push_back(p / q);
            break;
        }
        ll x = p / q + 1;
        result.push_back(x);
        q = q * x - p;
        p = p * x;
        //ll g = gcd(q, p);
        //q /= g;
        // p /= g;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << "1/" << result[i];
        if (i < result.size() - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll q, p;
        cin >> q >> p;
        if (q == 1) {
            cout << "1/" << p << endl;
            continue;
        }
        decompose_fraction(q, p);
    }
    return 0;
}
