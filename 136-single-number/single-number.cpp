class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int j = 0; j < nums.size(); j++) {
            int count = 0;
            int digit = nums[j];
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == digit) {
                    count++;
                }
            }
            if (count == 1) {
                return digit;
            }
        }
        return 0;
    }
};