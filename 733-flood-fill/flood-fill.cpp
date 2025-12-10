class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int oldcolor = image[sr][sc];
        if (oldcolor == color)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
           pair<int, int> s = q.front();
            q.pop();
            int cr = s.first;
            int cc = s.second;
            if (cr + 1 < image.size() && image[cr + 1][cc] == oldcolor) {
                image[cr + 1][cc] = color;
                q.push({cr + 1, cc});
            }
            if (cr - 1 < image.size() && image[cr - 1][cc] == oldcolor) {
                image[cr - 1][cc] = color;
                q.push({cr - 1, cc});
            }
            if (cc + 1 < image[0].size() && image[cr][cc + 1] == oldcolor) {
                image[cr][cc + 1] = color;
                q.push({cr, cc + 1});
            }
            if (cc - 1 < image[0].size() && image[cr][cc - 1] == oldcolor) {
                image[cr][cc - 1] = color;
                q.push({cr, cc - 1});
            }
        }
        return image;
    }
};