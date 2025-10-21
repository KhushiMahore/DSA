class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> sett;
            for (int j = 1; j < nums.size() - 1; j++) {
                int i = 0;
                int k = nums.size() - 1; while (i < j && j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                        sett.insert({nums[i], nums[j], nums[k]});
                    if (sum < 0) {
                        i++;
                    } else {
                        k--;
                    }
                }
            }

            vector<vector<int>> ans;
            for (vector<int> arr : sett) {
                ans.push_back(arr);
            }
            return ans;
        }
    
};