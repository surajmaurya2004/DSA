class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftGain = max(0, solve(root->left));
        int rightGain = max(0, solve(root->right));

        int currentPath = root->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPath);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};