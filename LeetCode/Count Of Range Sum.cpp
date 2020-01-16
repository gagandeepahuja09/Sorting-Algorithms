class Solution {
public:
    void merge(vector<int>& A, int l, int r) {
        int k = l, m = (l + r) / 2;
        vector<int> left, right;
        for(int i = l; i <= m; i++)
            left.push_back(A[i]);
        for(int i = m + 1; i <= r; i++)
            right.push_back(A[i]);
        k = l;
        int i = 0, j = 0;
        while(i < left.size() && j < right.size()) {
            if(left[i] <= right[j]) {
                A[k++] = left[i++];
            }
            else {
                A[k++] = right[j++];
            }
        }
    }
    
    int mergeSort(vector<int>& A, int l, int r, int lower, int upper) {
        if(l >= r)
            return 0;
        int m = (l + r) / 2;
        int ans = mergeSort(A, l, m, lower, upper) + mergeSort(A, m + 1, r, lower, upper);
        int j = m + 1, k = m + 1;
        for(int i = l; i <= m; i++) {
            while(j <= r && A[j] - A[i] <= upper)
                j++;
            while(k <= r && A[k] - A[i] < lower)
                k++;
            ans += (j - k);
        }
        merge(A, l, r);
        // inplace_merge(A.begin()+l, A.begin() + m + 1, A.begin() + r);
        return ans;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int> A(n + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            A[i] = A[i - 1] + nums[i - 1];    
        }
        return mergeSort(A, 0, n, lower, upper);
    }
};
