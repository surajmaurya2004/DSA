class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 means uncolored

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // not colored
                queue<int> q;
                q.push(i);
                color[i] = 0;  // start with color 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {  // uncolored neighbor
                            color[neighbor] = 1 - color[node];  // assign opposite color
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {  // conflict
                            return false;
                        }
                    }
                }
            }
        }
        return true;  // no conflicts found
    }
};