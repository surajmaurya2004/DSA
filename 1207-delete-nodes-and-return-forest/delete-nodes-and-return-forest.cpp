
class Solution {
public:
     unordered_set<int> del;
     vector<TreeNode*> result;
     TreeNode* dfs(TreeNode* root,bool isRoot){
        if(!root) return NULL;
        bool deleted = del.count(root->val);
        if(isRoot &&  !deleted){
            result.push_back(root);
        }
        root->left = dfs(root->left,deleted);
        root->right = dfs(root->right, deleted);
        return deleted ? NULL : root;
     }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x : to_delete)
        del.insert(x);
        dfs(root,true);
        return result;
        
    }
};