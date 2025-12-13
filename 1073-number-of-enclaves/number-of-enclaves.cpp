class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n));
        queue<pair<int, int>> queue;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        queue.push({i, j});
                        grid[i][j] = -1;
                    }
                }
            }
        }

        while (!queue.empty()) {
            pair<int, int> u = queue.front();
            int row = u.first;
            int col = u.second;
            queue.pop();
            pair<int, int> up = {row - 1, col};
            pair<int, int> down = {row + 1, col};
            pair<int, int> left = {row, col - 1};
            pair<int, int> right = {row, col + 1};

            if (up.first >= 0) {
                if (grid[up.first][up.second] == 1) {
                    grid[up.first][up.second] = -1;
                    queue.push(up);
                }
            }
            if (left.second >= 0) {
                if (grid[left.first][left.second] == 1) {
                    grid[left.first][left.second] = -1;
                    queue.push(left);
                }
            }
            if (down.first < m) {
                if (grid[down.first][down.second] == 1) {
                    grid[down.first][down.second] = -1;
                    queue.push(down);
                }
            }
            if (right.second < n) {
                if (grid[right.first][right.second] == 1) {
                    grid[right.first][right.second] = -1;
                    queue.push(right);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};