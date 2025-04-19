#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

//vector<int> v;

node *BuildTree(vector<int> values){
    if(values.empty() || values[0] == -1) return NULL;
    queue<node*> q;
    node *root = new node(values[0]);
    q.push(root);
    //v.push_back(values[0]);
    int i = 1;
    while(!q.empty()){
        node *current = q.front(); q.pop();
        if(i < values.size() && values[i] != -1){
            //v.push_back(v[i]);
            current->left = new node(values[i]);
            q.push(current->left);
        }
        i++;
        if(i < values.size() && values[i] != -1){
            current->right = new node(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

//vector<node*> v(1005);

void BFS(node *root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    vector<vector<int>> levels;
    while(!q.empty()){
        int sz = q.size();
        vector<int> level;
        for(int i = 0; i < sz; i++){
            node *current = q.front(); q.pop();
            level.push_back(current->data);
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        levels.push_back(level);
    }
    for(int i = levels.size() - 1; i >= 0; i--){
        for(int val : levels[i]){
            cout << val << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> values(n);
        for(int i = 0; i < n; i++){
            cin >> values[i];
        }
        node *root = BuildTree(values);
        BFS(root);
    }
}
