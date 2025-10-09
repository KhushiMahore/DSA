class Solution {
public:
    bool isPalindrome(int x) {
       long long int initial=x;

       long long int reverse = 0;
        if (x < 0) {
            return false;
        }
        while (x != 0) {
           long long int number = x % 10;
            reverse = reverse * 10 + number;
            x = x / 10;
        }
        if (initial == reverse) {
            return true;
        } 
        else {
            return false;
        }
    }
};