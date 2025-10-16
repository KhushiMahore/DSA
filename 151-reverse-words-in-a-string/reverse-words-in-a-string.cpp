class Solution {
public:
    string reverseWords(string s) {
          string temp = "";
        string ans = "";
        s = " " + s;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                temp = s[i] + temp;
            } else {
                if (temp != "" ) {
                    ans = ans + temp;
                    ans = ans + " ";
                    temp = "";
                }
            }
        }
        return ans.substr(0, ans.length()-1);
    }
};