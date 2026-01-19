class Solution {
public:
    void sub(vector<int>& nums, int index, vector<int> current,
                vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        sub(nums, index + 1, current, result);
        current.push_back(nums[index]);

        sub(nums, index + 1, current, result);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        sub(nums, 0, current, result);
        return result;
    }
};
