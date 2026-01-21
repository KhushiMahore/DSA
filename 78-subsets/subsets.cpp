class Solution {
public:
    vector<vector<int>> ans;

    void power(int s, vector<int>& nums, vector<int>& temp) {
        if (s == nums.size()) {
            ans.push_back(temp);
            return;
        }
        else{
        temp.push_back(nums[s]);
        power(s + 1, nums, temp);
        temp.pop_back();
        power(s + 1, nums, temp);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        power(0, nums, temp);
        return ans;
    }
};