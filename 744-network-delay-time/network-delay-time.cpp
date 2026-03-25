class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &t : times){
            adj[t[0]].push_back({t[1], t[2]});

        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(time + wt < dist[adjNode]){
                    dist[adjNode]  = time + wt;
                    pq.push({dist[adjNode],adjNode});

                }
            }
        }
        int ans = 0;
        for(int i = 1; i<= n;i++){
            if(dist[i] == INT_MAX)
            return -1;
            ans = max(ans,dist[i]);

        }
        return ans;
    }
};