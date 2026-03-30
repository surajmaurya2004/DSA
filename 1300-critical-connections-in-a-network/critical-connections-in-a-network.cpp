class Solution {
public:
    
    vector<vector<int>> result;
    vector<int> disc, low;
    vector<vector<int>> adj;
    int time = 0;
    
    void dfs(int node, int parent){
        
        disc[node] = low[node] = time++;
        
        for(int neighbor : adj[node]){
            
            if(neighbor == parent)
                continue;
            
            if(disc[neighbor] == -1){
                
                dfs(neighbor, node);
                
                low[node] = min(low[node], low[neighbor]);
                
                // bridge condition
                if(low[neighbor] > disc[node]){
                    result.push_back({node, neighbor});
                }
            }
            else{
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        adj.resize(n);
        
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        disc.assign(n, -1);
        low.assign(n, -1);
        
        dfs(0, -1);
        
        return result;
    }
};