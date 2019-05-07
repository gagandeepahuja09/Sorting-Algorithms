/*
Count of smaller numbers after self

Given an array of integers A, find and return new integer array B. B array has the property where B[i] is the number of smaller elements to the right of A[i].
*/

#define it vector<pair<int, int>>::iterator

void mergeSort(it l, it r, vector<int>& cnt) {
    if(r - l <= 1)
        return;
    it m = l + (r - l) / 2;
    mergeSort(l, m, cnt);
    mergeSort(m, r, cnt);
    for(it i = l, j = m; i < m; i++) {
        while(j < r && i -> first > j -> first)
            j++;
        cnt[i -> second] += (j - m);
    }
    inplace_merge(l, m, r);
}

vector<int> Solution::solve(vector<int> &A) {
    vector<pair<int, int>> vp;
    for(int i = 0; i < A.size(); i++) {
        vp.push_back({ A[i], i });
    }
    vector<int> cnt(A.size(), 0);
    mergeSort(vp.begin(), vp.end(), cnt);
    return cnt;
}

