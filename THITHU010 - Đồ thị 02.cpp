#include<bits/stdc++.h>

using namespace std;
// vì là cây nên không có chu trình
using ll = long long;
//Bước 1: Kiểm tra xem có nút nào có bậc vào bằng 2 không (tức là có 2 cạnh vào nút đó).
//Bước 2: Nếu có, ta cần loại bỏ một trong hai cạnh đó (ưu tiên cạnh xuất hiện sau trong danh sách). vì ưu tiên cạnh cuối nên ta kiểm tra nếu xoá cạnh cuối có tạo chu trình không nếu có thì trả về cạnh đầu tiên
//Bước 3: Nếu không có nút nào có bậc vào bằng 2, ta dùng DSU để kiểm tra chu trình (coi đồ thị là vô hướng).

int n;
int in_degree[1005];
int parent[1005];
int sz[1005];
vector<pair<int, int>> edges;

void nhap(){
    cin >> n;
    edges.clear();
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        edges.push_back({x, y});
        in_degree[y]++;
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = i;
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}


bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[u] = v;
    return true;
}

pair<int, int> solve(){
    int node = -1; // kiểm tra node nào có bán bậc vào = 2;
    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 2){
            node = i;
            break;
        }
    }
    init();
    if(node != -1){
        vector<pair<int, int>> candidates;
        for(auto e : edges){
            if(e.second == node){
                candidates.push_back({e.first, e.second});
            }
        }
        pair<int, int> last_edge = candidates.back(); //ưu tiên cạnh cuối;
        // kiểm tra có chu trình nếu xoá last_edge không
        bool has_cycle = false;
        for(auto e : edges){
            if(e == last_edge) continue;
            if(!Union(e.first, e.second)){
                has_cycle = true;
                break;
            }
        }
        if(!has_cycle) return last_edge;
        else return candidates.front();
    }
    init();
    pair<int, int> cycles;
    for(auto e : edges){
        if(!Union(e.first, e.second)){
            cycles = e;
            break;
        }
    }
    return cycles;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        //init();
        pair<int, int> res = solve();
        cout << res.first << " " << res.second << endl;
    }
}
