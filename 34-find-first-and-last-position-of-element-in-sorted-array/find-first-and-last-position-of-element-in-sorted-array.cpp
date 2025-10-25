class Solution {
public:
    int firstIndex(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans=-1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                ans = mid;
            }
            if (nums[mid] >= target) {
              high = mid - 1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
    int lastIndex(vector<int>& nums, int target) { 
    
         int low = 0;
        int high = nums.size() - 1;
        int ans=-1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                ans = mid;
            }
            if (nums[mid] > target) {
              high = mid - 1;
            } else {
                low=mid+1;
            }
        }
        
        return ans; }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstIndex(nums, target);
        int last = lastIndex(nums, target);
        return {first, last};
    }
};