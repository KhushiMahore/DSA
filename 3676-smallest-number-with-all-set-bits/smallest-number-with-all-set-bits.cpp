class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        while (n > 0) {
            n = n / 2;
            ans = ans * 2 + 1;
        }
        return ans;
    }
};