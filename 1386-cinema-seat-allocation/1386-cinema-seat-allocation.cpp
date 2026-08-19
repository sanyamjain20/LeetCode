class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int ans = 2 * n;
        int i = 0;
        while (i < reservedSeats.size()) {
            ans -= 2;
            int row = reservedSeats[i][0];
            bool l = true;
            bool r = true;
            bool m = true;
            while (i < reservedSeats.size() && reservedSeats[i][0] == row) {
                int seat = reservedSeats[i][1];
                if (seat >= 2 && seat <= 5)
                    l = false;

                if (seat >= 4 && seat <= 7)
                    m = false;

                if (seat >= 6 && seat <= 9)
                    r = false;
                i++;
            }
            if (l && r)
                ans += 2;
            else if (l || r || m)
                ans += 1;
        }
        return ans;
    }
};