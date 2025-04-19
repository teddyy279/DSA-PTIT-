#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node *BuildTree(vector<int> values){
    if (values.empty() || values[0] == -1) return NULL;
    queue<node*> q;
    node *root = new node(values[0]);
    q.push(root);
    int i = 1;
    while (!q.empty()){
        node *current = q.front(); q.pop();
        if (i < values.size() && values[i] != -1){
            current->left = new node(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1){
            current->right = new node(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void PrintRight(node *root){
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++){
            node *current = q.front(); q.pop();
            // Chỉ in nút cuối cùng của mỗi tầng (rightmost node)
            if (i == sz - 1){
                cout << current->data << " ";
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> values(n);
        for (int i = 0; i < n; i++){
            cin >> values[i];
        }
        node *root = BuildTree(values);
        PrintRight(root); 
        cout << endl;
    }
}
