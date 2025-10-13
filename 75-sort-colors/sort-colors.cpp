class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int greatest= 0;
        int greatestIndex=0;
        //{2,0,2,1,1,0}
        //{0,0,2,1,1,2}
        //{0,0,1,1,2,2}
        //{0,0,1,1,2,2}

        //{0,0,1,1,2,2}

        for (int i = 0; i < nums.size(); i++)
        {

            for (int j = 0; j < nums.size() - i; j++)
            {
                if (nums[j] > greatest)
                {
                    greatest = nums[j];
                    greatestIndex=j;
                }
            }
            
            // nums[nums.size()-1]=greatest;
            swap(nums[nums.size() - 1 - i], nums[greatestIndex]);
            greatest=0;
            greatestIndex=0;
        }
        
    }
};