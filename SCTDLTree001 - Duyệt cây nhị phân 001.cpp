#include <bits/stdc++.h>
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


node *BuildTree(vector<int> values){
    if (values.empty() || values[0] == -1) return NULL;
    node *root = new node(values[0]);
    queue<node*> q;
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

// Hàm in cây theo cấp độ
void PrintByLevel(node *root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node *current = q.front(); q.pop();
            cout << current->data << " ";
            //if (i < size - 1) cout << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

int main(){
    int t; cin >> t;
    cin.ignore();  
    while (t--){
        int n;  
        cin >> n;
        vector<int> values(n);
        for (int i = 0; i < n; ++i){
            cin >> values[i];
        }
        node *root = BuildTree(values);  
        PrintByLevel(root);  
    }
    return 0;
}
