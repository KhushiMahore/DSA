class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> reverse(n);
        vector<int> out(n, 0);

        
        for (int i = 0; i < n; i++) {
            out[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); j++) {
                int v = graph[i][j];
                reverse[v].push_back(i);
            }
        }

        queue<int> q;

        
        for (int i = 0; i < n; i++) {
            if (out[i] == 0)
                q.push(i);
        }

        vector<int> safe;

      
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int i = 0; i < reverse[node].size(); i++) {
                int prev = reverse[node][i];
                out[prev]--;

                if (out[prev] == 0)
                    q.push(prev);
            }
        }

        
        sort(safe.begin(), safe.end());
        return safe;
    }
};