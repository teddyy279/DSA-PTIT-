#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node (int x){
        data = x;
        left = right = NULL;
    }
};

node *BuildTree(vector<int> values){
    if(values.empty() || values[0] == -1) return NULL;
    queue<node*> q;
    node *root = new node(values[0]);
    q.push(root);
    int i = 1;
    while(!q.empty()){
        node *current = q.front(); q.pop();
        if(i < values.size() && values[i] != -1){
            current->left = new node(values[i]);
            q.push(current->left);
        }
        i++;
        if(i <values.size() && values[i] != -1){
            current->right = new node(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void DFS(node *root, vector<int> &path, vector<vector<int>> &res){
    if(root == NULL) return;
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        res.push_back(path);
    }
    DFS(root->left, path, res);
    DFS(root->right, path, res);
    path.pop_back();
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
        vector<int> path;
        vector<vector<int>> res;
        DFS(root, path, res);
        if(res.empty()){
            cout << 0 << "\n";
        }
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[i].size(); j++){
                cout << res[i][j];
                if(j < res[i].size() - 1) cout << "->";
            }
            cout << endl;
        }
    }
}
