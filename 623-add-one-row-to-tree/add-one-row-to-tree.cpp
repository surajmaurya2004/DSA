
class Solution {
public:
    void dfs(TreeNode* root,int val, int depth,int level){
        if(root == NULL) return;
        if(level == depth - 1){
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            return;
        }
        dfs(root->left, val,depth,level + 1);
        dfs(root->right, val,depth,level + 1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root,val,depth, 1);
        return root;
        
    }
};