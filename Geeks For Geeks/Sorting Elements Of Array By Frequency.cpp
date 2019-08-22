#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if(a.second.first == b.second.first)
        return a.first < b.first; // a.second.second < b.second.second 
    return a.second.first > b.second.first;     
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> A(n);
        for(int i = 0; i < n; i++) {
            cin >> A[i].first;
            A[i].second.second = i;
        }
        stable_sort(A.begin(), A.end());
        A[0].second.first = 1;
        for(int i = 1; i < n; i++) {
            if(A[i].first == A[i - 1].first) {
                A[i].second.first = A[i - 1].second.first + 1;
                A[i - 1].second.first = -1;
                A[i].second.second = A[i - 1].second.second;
            }
            else {
                A[i].second.first = 1;
            }
        }
        sort(A.begin(), A.end(), cmp);
        vector<int> ret;
        for(int i = 0; i < A.size(); i++) {
            // cout << A[i].first << " " << A[i].second.first 
            // << " " << A[i].second.second << endl;
            if(A[i].second.first == -1)
                break;
            for(int j = 0; j < A[i].second.first; j++) {
                cout << A[i].first << " ";
            }    
        }
        cout << endl;
    }
	return 0;
}
