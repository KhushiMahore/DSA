class Solution {
public:
    void bfs(int start, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[node][j] == 1 && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, isConnected, visited);
            }
        }

        return count;
    }
};