#define iterator vector<vector<int>>::iterator

class Solution {
private:
    void mergeSort(iterator l, iterator r, vector<int>& ret) {
        if(r - l <= 1)
            return;
        iterator m = l + (r - l) / 2;
        mergeSort(l, m, ret);
        mergeSort(m, r, ret);
        for(iterator i = l, j = m; i < m; i++) {
            while(j < r && (*i)[0] > (*j)[0])
                j++;
            ret[(*i)[1]] += (j - m);
        }
        inplace_merge(l, m, r);
    }
    
public:    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<vector<int>> temp;
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back( vector<int>({ nums[i], i }) );
        }
        mergeSort(temp.begin(), temp.end(), ret);
        return ret;
    }
};
