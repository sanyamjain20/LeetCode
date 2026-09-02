class Solution {
public:
    void heapify(vector<int>& heap, int i, int size) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(heap, largest, size);
        }
    }
    void heapsort(vector<int>& heap, int size) {
        if (size <= 1)
            return;
        swap(heap[0], heap[size - 1]);
        heapify(heap, 0, size - 1);
        heapsort(heap, size - 1);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, i, n);
        heapsort(nums, n);

        return nums;
    }
};