#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *BuildTree(vector<int> &values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode *current = q.front();
        q.pop();

        // Left child
        if (i < values.size()) {
            if (values[i] != -1) {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }
            i++;
        }

        // Right child
        if (i < values.size()) {
            if (values[i] != -1) {
                current->right = new TreeNode(values[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}



pair<int, int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    int include = node->val + left.second + right.second;
    int exclude = max(left.first, left.second) + max(right.first, right.second);
    return {include, exclude};
}

int rob(TreeNode* root) {
    auto res = dfs(root);
    return max(res.first, res.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; i++) cin >> nodes[i];

        if (n == 0 || nodes[0] == -1) {
            cout << "0\n";  // Không có cây
            continue;
        }

        TreeNode* root = BuildTree(nodes);
        cout << rob(root) << "\n";
    }
    return 0;
}
