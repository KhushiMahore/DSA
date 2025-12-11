class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        if (count == 0) return 0;

        int minutes = -1;

        while (!q.empty()) {

            int size = q.size();
            minutes++;

            while (size--) {
                pair<int,int> s = q.front();
                q.pop();

                int cr = s.first;
                int cc = s.second;

           
                if (cr + 1 < n && grid[cr + 1][cc] == 1) {
                    grid[cr + 1][cc] = 2;
                    count--;
                    q.push({cr + 1, cc});
                }

              
                if (cr - 1 >= 0 && grid[cr - 1][cc] == 1) {
                    grid[cr - 1][cc] = 2;
                    count--;
                    q.push({cr - 1, cc});
                }

            
                if (cc + 1 < m && grid[cr][cc + 1] == 1) {
                    grid[cr][cc + 1] = 2;
                    count--;
                    q.push({cr, cc + 1});
                }

                
                if (cc - 1 >= 0 && grid[cr][cc - 1] == 1) {
                    grid[cr][cc - 1] = 2;
                    count--;
                    q.push({cr, cc - 1});
                }
            }
        }

      
        if (count > 0)
            return -1;
        return minutes;
    }
};