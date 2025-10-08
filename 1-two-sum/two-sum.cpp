class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int indexA, indexB;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indexA = i;
                    indexB = j;
                }
            }
        }
        return {indexA, indexB};
    }
};