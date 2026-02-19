
class Solution {
public:
  void create_adj(TreeNode* root,TreeNode* parent, unordered_map<TreeNode*,vector<TreeNode*>> &adj_list){
    if(!root) return;
    adj_list[root].push_back(parent);
    adj_list[root].push_back(root->left);
    adj_list[root].push_back(root->right);
    create_adj(root->left,root,adj_list);
    create_adj(root->right,root,adj_list);
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> adj_list;
        create_adj(root,nullptr,adj_list);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> isVisited;
        isVisited.insert(target);
        int distance = 0;
        while(!q.empty() && distance<k){
            int n = q.size();
            for(int i = 0;i<n;i++){
                auto node = q.front();
                q.pop();
                for(auto child: adj_list[node]){
                    if(child!= nullptr && isVisited.find(child) == isVisited.end()){
                        isVisited.insert(child);
                        q.push(child);
                    }
                }
            }
            distance++;
        }
   
     vector<int> res;
     while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
        }
        return res;
    }
};