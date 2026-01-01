class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        ans.push_back("");   

        for (char d : digits) {
            vector<string> temp;
            string letters = mp[d - '0'];

            for (string s : ans) {
                for (char ch : letters) {
                    temp.push_back(s + ch);
                }
            }
            ans = temp;
        }

        return ans;
    }
};
