class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> s;

        for (int i = 0; i < n; i++) {
            int h = digits[i];
            if (h == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                int t = digits[j];
                for (int k = 0; k < n; k++) {
                    int o = digits[k];
                    if (o % 2 == 1 || k == i || k == j)
                        continue;
                    s.insert(h * 100 + t * 10 + o);
                }
            }
        }
        return s.size();
    }
};