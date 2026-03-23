class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    int getTotalSum(TreeNode* root){
        if(!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int subSum = root->val + left + right;

        long long product = (long long)subSum * (totalSum - subSum);
        maxProd = max(maxProd, product);

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};