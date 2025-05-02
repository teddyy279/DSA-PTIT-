#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* Insert(node* root, int x){
    if(root == NULL) return new node(x);
    if(x < root->data) root->left = Insert(root->left, x);
    else root->right = Insert(root->right, x);
    return root;
}

node* minNode(node* root){
    node* tmp = root;
    while(tmp && tmp->left) tmp = tmp->left;
    return tmp;
}

node* Delete(node* root, int x){
    if(root == NULL) return NULL;
    if(x < root->data) root->left = Delete(root->left, x);
    else if(x > root->data) root->right = Delete(root->right, x);
    else {
        if(root->left == NULL){
            node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == NULL){
            node* tmp = root->left;
            delete root;
            return tmp;
        }
        else{
            node* tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
}

void preorder(node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    node* root = NULL;
    string cmd;
    int x;
    for(int i = 1; i <= q; i++){
        cin >> cmd >> x;
        if(cmd == "ins") root = Insert(root, x);
        else if(cmd == "del") root = Delete(root, x);
        cout << "Query #" << i << ": ";
        preorder(root);
        cout << "\n";
    }
}
