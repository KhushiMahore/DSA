class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i, vector<int>& c, int target, vector<int>& cur) {
       
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

      
        if (i == c.size() || target < 0)
            return;

        cur.push_back(c[i]);
        helper(i, c, target - c[i], cur);
        cur.pop_back();   

        
        helper(i + 1, c, target, cur);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        helper(0, candidates, target, cur);
        return ans;
    }
};
