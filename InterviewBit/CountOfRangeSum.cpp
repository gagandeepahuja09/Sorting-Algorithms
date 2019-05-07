/*
Count of Range Sum

Given an array of integers A and two integers B and C. Find the number of range sums that lie in [ B, C ] inclusive.

Range sum S(i, j) is defined as the sum of the elements in A between indices i and j (i ≤ j), inclusive.*/


#define it vector<int>::iterator

int mergeSort(it l, it r, int B, int C) {
    if(r - l <= 1)
        return 0;
    it m = l + (r - l) / 2;
    int cnt = mergeSort(l, m, B, C) + mergeSort(m, r, B, C);
    for(it i = l, j1 = m, j2 = m; i < m; i++) {
        while(j1 < r && (*j1) - (*i) < B)    j1++;
        while(j2 < r && (*j2) - (*i) <= C)   j2++;
        cnt += (j2 - j1);
    }
    inplace_merge(l, m, r);
    return cnt;
}

int Solution::solve(vector<int> &A, int B, int C) {
    vector<int> p(A.size() + 1, 0);
    for(int i = 0; i < A.size(); i++)
        p[i + 1] = p[i] + A[i];
    return mergeSort(p.begin(), p.end(), B, C);
}

