class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1)
            return -1;

        long long p = value;

        if (value % 2 == 0) {
            p = 2;
        } 
        else {
            for (long long i = 3; i <= value / i; i += 2) {
                if (value % i == 0) {
                    p = i;
                    break;
                }
            }
        }

        long long left = index;
        long long right = n - 1 - index;

        // Check whether the left side is possible
        if (left > 0) {
            long long smallest = value - p - 2 * (left - 1);

            if (smallest <= 0)
                return -1;
        }

        // Calculate the maximum element
        if (right == 0)
            return value;

        return value + p + 2 * (right - 1);
    }
};