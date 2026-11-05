class Solution {
public:
    int binarySearch(vector<int> arr, int tar) {
        int l = 0;
        int h = arr.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] < tar)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        for (int& x : arr1) {
            int idx = binarySearch(arr2, x);
            bool valid = true;

            if (abs(x - arr2[idx]) <= d)
                valid = false;

            if (idx > 0 && abs(x - arr2[idx - 1]) <= d)
                valid = false;

            if (valid)
                ans++;
        }
        return ans;
    }
};