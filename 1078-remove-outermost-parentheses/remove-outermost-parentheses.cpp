class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (count != 0)
                    ans += s[i];
                count++;
            } else {
                if (s[i] == ')') {
                    count--;
                    if (count != 0)
                        ans += s[i];
                }
            }
        }
        return ans;
    }
};