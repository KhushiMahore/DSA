class Solution {
public:
    long long int reverse(int n) {
        long long int ans = 0;
        bool negative = false;
        if(n == INT_MIN) return 0;
        if (n < 0) {
            negative = true;
            n = n * (-1);
        }

        while (n > 0) {

            int digit = n % 10;
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            n = n / 10;
            ans = ans * 10;
            ans = digit + ans;
        }
        if (negative == true)
            ans = ans * (-1);
        return ans;
    }
};