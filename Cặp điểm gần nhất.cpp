 #include <bits/stdc++.h>
using namespace std;

double distance(pair<int, int> a, pair<int, int> b){
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double closestPair(vector<pair<int, int>> &points){
    int n = points.size();
    if(n <= 3){
        double minDist = DBL_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
        return minDist;
    }
    int mid = n / 2;
    vector<pair<int, int>> left(points.begin(), points.begin() + mid);
    vector<pair<int, int>> right(points.begin() + mid, points.end());
    
    // Tìm khoảng cách ngắn nhất ở phần trái và phần phải
    double leftMin = closestPair(left);
    double rightMin = closestPair(right);

    // Tính khoảng cách nhỏ nhất trong 2 phần
    double minDist = min(leftMin, rightMin);

    vector<pair<int, int>> strip;
    int midX = points[mid].first;

    // Chỉ thêm những điểm gần đường chia (theo trục x)
    for(int i = 0; i < n; i++){
        if(abs(points[i].first - midX) < minDist){
            strip.push_back(points[i]);
        }
    }

    // Sắp xếp các điểm trong strip theo trục y
    sort(strip.begin(), strip.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });
     
    for(int i = 0; i < strip.size(); i++){
        for(int j = i + 1; j < strip.size() && abs(strip[i].second - strip[j].second) < minDist; j++){
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}
                
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> points(n);
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            points[i] = {x, y};
        }
        sort(points.begin(), points.end());
        cout << fixed << setprecision(6) << closestPair(points) << endl;
    }
}
