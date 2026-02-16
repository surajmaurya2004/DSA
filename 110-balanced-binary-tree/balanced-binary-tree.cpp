
class Solution {
public:
        int ans = true;
        int helper(TreeNode* root){
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if(abs(left-right)>1) ans = false;
        return max(left,right) +1;
        
    }
    bool isBalanced(TreeNode* root){
        helper(root);
        return ans;
    }
};