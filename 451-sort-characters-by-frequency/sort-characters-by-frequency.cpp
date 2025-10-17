class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
        }
        vector<int> countVal;
        for (auto it : mpp) {
            countVal.push_back(it.second);
        }
        sort(countVal.begin(), countVal.end(), greater<int>());
        string ans = "";
        int isVisited[100000] = {0};
        for (int i = 0; i < countVal.size(); i++) {
            for (auto it : mpp) {
                if (it.second == countVal[i] && isVisited[countVal[i]] == 0) {
                    ans += string(it.second, it.first);
                }
            }
            isVisited[countVal[i]] = 1;
        }
        return ans;
    }
}
;