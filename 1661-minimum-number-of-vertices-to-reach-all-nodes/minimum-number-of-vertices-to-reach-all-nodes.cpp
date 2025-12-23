class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> income(n, 0);

       
        for (int i = 0; i < edges.size(); i++) {
            income[edges[i][1]] = 1;
        }

        vector<int> result;

       
        for (int i = 0; i < n; i++) {
            if (income[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};
