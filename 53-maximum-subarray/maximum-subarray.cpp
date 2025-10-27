class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if (sum > largestSum) {
                largestSum = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return largestSum;
    }
};