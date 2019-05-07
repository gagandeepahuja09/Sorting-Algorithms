/*Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].

Return the number of important reverse pairs in the given array A*/

#define it vector<int>::iterator

int mergeSort(it l, it r) {
    if(r - l <= 1)
        return 0;
    it m = l + (r - l) / 2;    
    int cnt = mergeSort(l, m);
    cnt += mergeSort(m, r);
    for(it i = l, j = m; i < m; i++) {
        while(j < r && *i > 2 * *j) {
            j++;
        }
        cnt += (j - m);
    }
    inplace_merge(l, m, r);
    return cnt;
}

int Solution::solve(vector<int> &A) {
    return mergeSort(A.begin(), A.end());
}
