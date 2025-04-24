#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void compressArray(vector<long long> &A, unordered_map<long long, int> &compressed){
    vector<long long> temp = A;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i = 0; i < temp.size(); i++){
        compressed[temp[i]] = i + 1;// ánh xạ giá trị gốc -> giá trị nén [1, N];
    }
}

class SegmentTree{
private:
    vector<int> tree;
    int n;
public:
    SegmentTree(int size){
        n = size;
        tree.resize(n * 4, 0);
    }

    void update(int idx, int left, int right, int pos){
        if(left == right){
            tree[idx]++;
            return;
        }
        int mid = (left + right) / 2;
        if(pos <= mid){
            update(2 * idx, left, mid, pos);
        }
        else{
            update(2 * idx + 1, mid + 1, right, pos);
        }
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int query(int idx, int left, int right, int ql, int qr){
        if(ql > qr) return 0;
        if(left == ql && right == qr){
            return tree[idx];
        }
        else{
            int mid = (left + right) / 2;
            return query(idx * 2, left, mid, ql, min(mid, qr)) + query(idx * 2 + 1, mid + 1, right, max(ql, mid + 1), qr);
        }
    }
};


long long countInversions(vector<long long> &v){
    unordered_map<long long, int> compressed;
    compressArray(v, compressed);
    int max_compress_value = 0;
    for(auto &num : v){
        num = compressed[num];
        max_compress_value = max(max_compress_value, (int)num);
    }

    SegmentTree ST(max_compress_value);
    long long invCount = 0;
    for(int i = v.size() - 1; i >= 0; i--){
        invCount += ST.query(1, 1, max_compress_value, 1, v[i] - 1);
        ST.update(1, 1, max_compress_value, v[i]);
    }
    return invCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        cout << countInversions(v) << "\n"; 
    }
}
