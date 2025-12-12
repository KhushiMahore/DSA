class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n));
        queue<pair<int, int>> queue;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    queue.push({i, j});
                    distance[i][j] = 0;
                } else {
                    distance[i][j] = -1;
                }
            }
        }
        while (!queue.empty()) {
            pair<int, int> u = queue.front();
            int row = u.first;
            int col = u.second;
            int dis = distance[row][col];
            queue.pop();
            pair<int, int> up = {row - 1, col};
            pair<int, int> down = {row + 1, col};
            pair<int, int> left = {row, col - 1};
            pair<int, int> right = {row, col + 1};

            if (up.first >= 0) {
                if (distance[up.first][up.second] == -1) {
                    distance[up.first][up.second] = dis + 1;
                    queue.push(up);
                }
            }
            if (left.second >= 0) {
                if (distance[left.first][left.second] == -1) {
                    distance[left.first][left.second] = dis + 1;
                    queue.push(left);
                }
            }
            if (down.first < m) {
                if (distance[down.first][down.second] == -1) {
                    distance[down.first][down.second] = dis + 1;
                    queue.push(down);
                }
            }
            if (right.second < n) {
                if (distance[right.first][right.second] == -1) {
                    distance[right.first][right.second] = dis + 1;
                    queue.push(right);
                }
            }
        }
        return distance;
    }
};