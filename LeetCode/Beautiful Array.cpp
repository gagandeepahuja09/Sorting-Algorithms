class Solution {
public:
    void merge(vector<int>& ret, vector<int>& odd, vector<int>& even, int l, int r) {
        int m = (l + r) / 2;
        int i = l;
        for(int k = 0; k < odd.size(); i++, k++) {
            ret[i] = odd[k];
        }
        for(int k = 0 ; k < even.size(); i++, k++) {
            ret[i] = even[k];
        }
    }
    
    void divide(vector<int>& ret, int l, int r) {
        if(l >= r)
            return;
        vector<int> odd, even;
        for(int i = l; i <= r; i++) {
            if(((i - l) % 2) == 1) {
                odd.push_back(ret[i]);
            }
            else {
                even.push_back(ret[i]);
            }
        }
        merge(ret, even, odd, l, r);
        int m = (l + r) / 2;
        divide(ret, l, m);
        divide(ret, m + 1, r);
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> ret;
        for(int i = 1; i <= N; i++)
            ret.push_back(i);
        divide(ret, 0, N - 1);
        return ret;
    }
};
