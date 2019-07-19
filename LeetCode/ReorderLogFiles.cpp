class Solution {
public:
    static bool cmp(string a, string b) {
        int i = a.find(' ');
        int j = b.find(' ');
        
        if(isdigit(a[i + 1])) {
            if(isdigit(b[j + 1]))   // both are digit, follow same order
                return false;
            else
                return false;   // a is digit log, b is letter log a > b
        }
        else {
            if(isdigit(b[j + 1]))   // a is letter, b is digit
                return true;
            else {
                if(a.substr(i) == b.substr(j))  // in case of tie look at identifier
                    return a.substr(0, i) < b.substr(0, j);
                else 
                    return a.substr(i) < b.substr(j);
            }
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
