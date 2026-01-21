class Solution {
public:
  vector<vector<int>> ans;

    void power(int s, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);
        for (int i = s; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            power(i + 1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        power(0, nums, temp);
        return ans;
    }
};