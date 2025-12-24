class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        bool dead[10000] = {false};
        bool visited[10000] = {false};

        for (int i = 0; i < deadends.size(); i++) {
            int num = 0;
            for (int j = 0; j < 4; j++)
                num = num * 10 + (deadends[i][j] - '0');
            dead[num] = true;
        }

        int targetNum = 0;
        for (int i = 0; i < 4; i++)
            targetNum = targetNum * 10 + (target[i] - '0');

        if (dead[0]) return -1;

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == targetNum)
                    return moves;

                int temp = curr;
                int digits[4];

                for (int i = 3; i >= 0; i--) {
                    digits[i] = temp % 10;
                    temp /= 10;
                }
                for (int i = 0; i < 4; i++) {

                    int original = digits[i];

                    digits[i] = (original + 1) % 10;
                    int up = 0;
                    for (int k = 0; k < 4; k++)
                        up = up * 10 + digits[k];

                    if (!dead[up] && !visited[up]) {
                        visited[up] = true;
                        q.push(up);
                    }

                    digits[i] = (original + 9) % 10;
                    int down = 0;
                    for (int k = 0; k < 4; k++)
                        down = down * 10 + digits[k];

                    if (!dead[down] && !visited[down]) {
                        visited[down] = true;
                        q.push(down);
                    }

                    digits[i] = original; 
                }
            }
            moves++;
        }

        return -1;
    }
};
