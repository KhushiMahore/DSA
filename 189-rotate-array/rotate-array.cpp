class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k = k % nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    }
    //     int n = nums.size();
    //     k = k % n;
    //     for (int j = 0; j < k; j++) {
    //         int lastIndex = nums.size() - 1;
    //         int lastElement = nums[lastIndex];
    //         for (int i = lastIndex; i > 0; i--) {
    //             nums[i] = nums[i - 1];
    //         }
    //         nums[0] = lastElement;
    //     }
    // }
   
};