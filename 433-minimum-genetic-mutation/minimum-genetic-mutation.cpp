class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        int steps = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string curr = q.front();
                q.pop();

                if (curr == endGene)
                    return steps;

                for (int i = 0; i < curr.length(); i++) {
                    char old = curr[i];

                    for (int j = 0; j < 4; j++) {
                        char ch;
                        if (j == 0) ch = 'A';
                        else if (j == 1) ch = 'C';
                        else if (j == 2) ch = 'G';
                        else ch = 'T';

                        if (ch == old) continue;

                        curr[i] = ch;

                     
                        for (int k = 0; k < bank.size(); k++) {
                            if (bank[k] == curr) {
                                q.push(curr);
                                bank[k] = "";  
                                break;
                            }
                        }
                    }
                    curr[i] = old;
                }
            }
            steps++;
        }
        return -1;
    }
};
