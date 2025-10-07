class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool power = true;
        int a = 0;
        if (n == 1) {
            return true;
        }
        if (n % 2 == 1) {
            return false;
        }
        while (n > 0) {
            if (n % 2 == 1)
                a++;
            n = n / 2;
        }
        if (a == 1) {
            return true;
        } else {
            return false;
        }
    }
};