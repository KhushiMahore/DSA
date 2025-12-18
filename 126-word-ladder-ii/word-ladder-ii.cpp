class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_set<string> dict;
    vector<vector<string>> ans;
    vector<string> path;

    void bfs(string beginWord, string endWord) {
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;

            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();

                for (int j = 0; j < curr.size(); j++) {
                    string next = curr;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == curr[j]) continue;
                        next[j] = c;

                        if (dict.count(next) && !visited.count(next)) {
                            parent[next].push_back(curr);

                            if (!levelVisited.count(next)) {
                                levelVisited.insert(next);
                                q.push(next);
                            }

                            if (next == endWord)
                                found = true;
                        }
                    }
                }
            }

            for (auto &w : levelVisited)
                visited.insert(w);
        }
    }

    void dfs(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            ans.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (auto &p : parent[word])
                dfs(p, beginWord);
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        dict = unordered_set<string>(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        bfs(beginWord, endWord);
        dfs(endWord, beginWord);

        return ans;
    }
};

