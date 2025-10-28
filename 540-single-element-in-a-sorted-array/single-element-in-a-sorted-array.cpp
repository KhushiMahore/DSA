class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1)
                mid--;

            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid - 1;
        }

        return nums[low];
    }
};