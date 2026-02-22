
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long start = q.front().second;
            long long end = start;
            for(int i = 0;i<size;i++){
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                long long index = curr.second - start;
                end = index;
                if(node->left)
                 q.push({node->left,2*index});
                 if(node->right)
                   q.push({node->right,2*index + 1});

            }
            maxWidth = max(maxWidth,end  + 1);
        }        
        return maxWidth;
    }
};