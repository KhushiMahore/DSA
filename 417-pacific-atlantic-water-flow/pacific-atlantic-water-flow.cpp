class Solution {
public:
    void BFS(vector<vector<int>>& heights, queue<pair<int, int>>& queue,
             vector<vector<bool>>& visited, int m, int n) {

        while (!queue.empty()) {
            pair<int, int> u = queue.front();
            queue.pop();

            int row = u.first;
            int col = u.second;

            int h = heights[row][col];

            pair<int, int> up = {row - 1, col};
            pair<int, int> down = {row + 1, col};
            pair<int, int> left = {row, col - 1};
            pair<int, int> right = {row, col + 1};

            if (up.first >= 0 && !visited[up.first][up.second]) {
                if (heights[up.first][up.second] >= h) {
                    visited[up.first][up.second] = true;
                    queue.push(up);
                }
            }

            if (left.second >= 0 && !visited[left.first][left.second]) {
                if (heights[left.first][left.second] >= h) {
                    visited[left.first][left.second] = true;
                    queue.push(left);
                }
            }

            if (down.first < m && !visited[down.first][down.second]) {
                if (heights[down.first][down.second] >= h) {
                    visited[down.first][down.second] = true;
                    queue.push(down);
                }
            }

            if (right.second < n && !visited[right.first][right.second]) {
                if (heights[right.first][right.second] >= h) {
                    visited[right.first][right.second] = true;
                    queue.push(right);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;

        for (int i = 0; i < m; i++) {
            pac[i][0] = true;
            pacQueue.push({i, 0});
        }
        for (int j = 0; j < n; j++) {
            pac[0][j] = true;
            pacQueue.push({0, j});
        }

        for (int i = 0; i < m; i++) {
            atl[i][n - 1] = true;
            atlQueue.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            atl[m - 1][j] = true;
            atlQueue.push({m - 1, j});
        }

        BFS(heights, pacQueue, pac, m, n);
        BFS(heights, atlQueue, atl, m, n);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};