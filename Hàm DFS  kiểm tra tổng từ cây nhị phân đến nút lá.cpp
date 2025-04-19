bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    
    sum -= root->val;
    
    // Nếu là lá và tổng bằng 0, trả về true
    if (root->left == NULL && root->right == NULL) {
        return sum == 0;
    }
    
    // Kiểm tra tiếp với cây con
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
