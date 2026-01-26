class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void power(int i, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
         if (k < 0 || n < 0)
            return;
        
        for (int j = i; j <= 9; j++) {
           
           
            temp.push_back(j);
            power(j + 1, k - 1, n - j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         power( 1,  k,  n);
        return  ans;
    }

}
;