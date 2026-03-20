class Solution {
public:
    
    int count = 0;
    
    vector<int> dfs(TreeNode* root, int distance){
        
        if(root == NULL)
            return {};
        
        if(!root->left && !root->right)
            return {1};
        
        vector<int> left = dfs(root->left , distance);
        vector<int> right = dfs(root->right , distance);
        
        // count valid pairs
        for(int l : left){
            for(int r : right){
                if(l + r <= distance)
                    count++;
            }
        }
        
        vector<int> result;
        
        // send distances to parent
        for(int l : left){
            if(l + 1 <= distance)
                result.push_back(l + 1);
        }
        
        for(int r : right){
            if(r + 1 <= distance)
                result.push_back(r + 1);
        }
        
        return result;
    }
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root , distance);
        return count;
    }
};