class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void power(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }  if (i == candidates.size()) {
            return;
        } else {
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                power(candidates, target - candidates[i], i);
                temp.pop_back();
               
            }
             power(candidates, target , i + 1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        power(candidates, target, 0);
        return ans;
    }
};