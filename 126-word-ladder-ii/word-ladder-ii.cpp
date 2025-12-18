class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> dict;
    string beginWord;

    void backtrack(string word, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for (string p : parent[word]) {
            path.push_back(p);
            backtrack(p, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        this->beginWord = beginWord;
        if (!dict.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            while (size--) {
                string word = q.front();
                q.pop();
                string original = word;

                for (int i = 0; i < word.size(); i++) {
                    char old = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (dict.count(word) && !visited.count(word)) {
                            if (word == endWord) found = true;
                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }
                            parent[word].push_back(original);
                        }
                    }
                    word[i] = old;
                }
            }
            for (auto w : levelVisited)
                visited.insert(w);
        }

        if (found) {
            vector<string> path;
            path.push_back(endWord);
            backtrack(endWord, path);
        }

        return ans;
    }
};
