class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {

        int n = friends.size();
        vector<int> visited(n, 0);
        queue<int> q;

        q.push(id);
        visited[id] = 1;

       
        for (int l = 0; l < level; l++) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();

                for (int j = 0; j < friends[u].size(); j++) {
                    int v = friends[u][j];
                    if (visited[v] == 0) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
        }

        
        vector<string> video;
        vector<int> freq;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (int i = 0; i < watchedVideos[person].size(); i++) {
                string v = watchedVideos[person][i];
                int found = 0;

                for (int j = 0; j < video.size(); j++) {
                    if (video[j] == v) {
                        freq[j]++;
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    video.push_back(v);
                    freq.push_back(1);
                }
            }
        }

       
        int m = video.size();
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (freq[j] > freq[j + 1] ||
                   (freq[j] == freq[j + 1] && video[j] > video[j + 1])) {
                    swap(freq[j], freq[j + 1]);
                    swap(video[j], video[j + 1]);
                }
            }
        }

        return video;
    }
};
