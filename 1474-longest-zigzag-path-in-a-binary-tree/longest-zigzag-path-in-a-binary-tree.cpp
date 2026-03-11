class Solution {
public:
    
    int ans = 0;
    
    void dfs(TreeNode* root, int direction, int length){
        
        if(root == NULL)
            return;
        
        ans = max(ans, length);
        
        if(direction == 0){ 
            dfs(root->right,1,length+1);
            dfs(root->left,0,1);
        }
        else{
            dfs(root->left,0,length+1);
            dfs(root->right,1,1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        
        dfs(root->left,0,1);
        dfs(root->right,1,1);
        
        return ans;
    }
};
