class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        int power = 1;
        while (n > 0) {
            int bit = n & 1;
            bit = bit ^ 1;
            ans = ans + (bit * power);
            power = power * 2;
            n = n >> 1;
        }
        return ans;
    }
        

};