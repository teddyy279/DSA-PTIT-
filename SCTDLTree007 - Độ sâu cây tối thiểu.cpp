#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

/*void makeRoot(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
} */

/*void insertNode(node *root, int u, int v, int c){
    if(root == NULL) return;
    if(root->data == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
} */


node *BuildTree(vector<int> values){
    if(values.empty() || values[0] == -1) return NULL;
    node *root = new node(values[0]);
    queue<node*> q;
    q.push(root);
    int i = 1;
    while(i < values.size()){
        node *current = q.front(); q.pop();
        if(i < values.size() && values[i] != -1){
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

//int max_height(node *root){
//    if(root == NULL) return 0;
//    else return max(max_height(root->left), max_height(root->right)) + 1;
//}

//void BFS(node *root){
//    if(root->empty())
//}

int minDepth(node* root) {
    if (!root) return 0;
    queue<node*> q;
    q.push(root);
    int depth = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node* node = q.front();
            q.pop();
            // Nếu gặp lá -> trả về độ sâu ngay lập tức
            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        depth++;
    }
    return depth; // Trường hợp cây chỉ có root
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
//        cout << max_height(root) << endl;
        cout << minDepth(root) << endl;
    }
}
