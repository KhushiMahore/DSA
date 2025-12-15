class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<int>& color, int node,
             int currColor) {
        color[node] = currColor;

        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                if (!DFS(graph, color, nei, 1 - currColor))
                    return false;
            } else if (color[nei] == currColor) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!DFS(graph, color, i, 0))
                    return false;
            }
        }
        return true;
    }
};