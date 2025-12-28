class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            vector<int> sub;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    sub.push_back(nums[j]);
                }
            }
            result.push_back(sub);
        }
        return result;
    }
};