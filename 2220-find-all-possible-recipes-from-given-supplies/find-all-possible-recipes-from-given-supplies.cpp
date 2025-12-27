class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> sup(supplies.begin(), supplies.end());
        vector<bool> made(recipes.size(), false);
        vector<string> ans;

        bool progress = true;

        while (progress) {
            progress = false;

            for (int i = 0; i < recipes.size(); i++) {
                if (made[i]) continue;

                bool canMake = true;

                for (string &i : ingredients[i]) {
                    if (!sup.count(i)) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    made[i] = true;
                    sup.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    progress = true;
                }
            }
        }

        return ans;
    }
};
