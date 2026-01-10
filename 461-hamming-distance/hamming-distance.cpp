class Solution {
public:
    int hammingDistance(int x, int y) {
        int xoor = x ^ y;
        int count = 0;

        while (xoor) {
            xoor &= (xoor-1);
            count++;
        }

        return count;
    }
};
