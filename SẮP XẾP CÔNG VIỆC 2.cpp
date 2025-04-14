#include<bits/stdc++.h>

using namespace std;

struct Job{
    int id, deadline, profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<Job> jobs(n);
        for(int i = 0; i < n; i++){
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }
        sort(jobs.begin(), jobs.end(), cmp);
        int cnt = 0, total_profit = 0;
        int max_deadline = 0;
        for(int i = 0; i < n; i++){
            max_deadline = max(jobs[i].deadline, max_deadline);
        }
        vector<int> check(max_deadline + 1, 0);
        for(int i = 0; i < n; i++){
            while(check[jobs[i].deadline] && jobs[i].deadline > 0) --jobs[i].deadline;
            if(!check[jobs[i].deadline] && jobs[i].deadline > 0){
                total_profit += jobs[i].profit;
                cnt++;      
                check[jobs[i].deadline] = 1;
            }
        }
        cout << cnt << " " << total_profit << endl;
    }
}
