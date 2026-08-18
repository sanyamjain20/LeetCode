class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int tc = 0;
        int cf = 0;
        for (int &r : requests) {
            tc += abs(r - cf);
            cf = r;
        }
        return tc;
    }
};