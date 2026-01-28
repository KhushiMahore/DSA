class Solution {
public:
 map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                               {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                               {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    void recursion(string &digits, int i, string &c) {
        if (i == digits.size()) {
            ans.push_back(c);
            return;
        }
        string s = mp[digits[i]];
        for (int j = 0; j < s.size(); j++) {
            c.push_back(s[j]);
            recursion(digits, i + 1, c);
            c.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return ans;
        string c="";
        recursion(digits, 0, c);
        return ans;
    }
};


// ha to ese karte ki pehle to ek loop banayenge ki jitne bhi digits h uske liye
// fir map se hum current vale digit ko nilaenge or ek loop banyenge har
// combination ke liye fir ek or banayenge current digit ke har letter ke liye
// fir lastr me dono ko add kar lenge or push kar denge ek var me loop nhi
// banayenge to saare possible conditions kese check hogi loop banake to kar
// sakte h na if else recursion ka use hoga? ek function banayenge fir usme
// digits i or abhi tk kitne combination bane vo arguments me daal denge fir
// pehle ki tarah condition laga denge ki i ==size tak ho gya to push kar de ans
// me fir loop lahenge? ek loop lagana hoga na combination ke liye fir loop
// lagayenge  usme har letterko add kr denge ha fir recursice call kr denge next
// vale ke liye fir vahi pop vala are mtlb pop kar denge removekr denge game ki
// baat nhi kiya  ho gya fir man function me ye sab map bana rhega or  fir apna
// recursion vala function daal denge main me fir return ans ho gya
