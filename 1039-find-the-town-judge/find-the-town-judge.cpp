class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for (int i = 1; i <= n; i++) {
            bool trustsSomeone = false;
            bool trustedByAll = true;

           
            for (int j = 0; j < trust.size(); j++) {
                if (trust[j][0] == i) {
                    trustsSomeone = true; 
                    break;
                }
            }

            if (trustsSomeone) continue;

            for (int j = 1; j <= n; j++) {
                if (j == i) continue;

                bool found = false;
                for (int k = 0; k < trust.size(); k++) {
                    if (trust[k][0] == j && trust[k][1] == i) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    trustedByAll = false;
                    break;
                }
            }

            if (trustedByAll)
                return i;
        }

        return -1;
    }
};
