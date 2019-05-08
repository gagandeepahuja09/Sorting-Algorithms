#define it vector<int>::iterator
#define MOD 1000000007
#define ll long long int

ll mergeSort(it l, it r) {
    if(r - l <= 1)
        return 0;
    it m = l + (r - l) / 2;
    ll cnt = (mergeSort(l, m) % MOD + mergeSort(m, r) % MOD) % MOD;
    for(it i = l, j = m; i < m; i++) {
        while(j < r && *i > *j) {
            j++;
        }
        cnt = (cnt % MOD + (j - m) % MOD) % MOD;
    }
    inplace_merge(l, m, r);
    return cnt;
}

int Solution::solve(vector<int> &A) {
    return (int)mergeSort(A.begin(), A.end());
}

