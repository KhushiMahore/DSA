class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) {
            return false;
        }
        if (s == goal) {
            return true;
        }
        for (int i = 1; i <= s.length(); i++) {
            string st = s;
            reverse(st.begin(), st.begin() + i);
             reverse(st.begin() + i, st.end());
             reverse(st.begin(), st.end());

            if (st == goal) {
                return true;
            }
        }
        return false;
    }
};