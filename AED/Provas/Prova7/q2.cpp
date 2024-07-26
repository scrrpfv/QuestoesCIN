#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> v, int begin) {
    int c = 0;
    for (int i = begin; i < v.size(); i++) c += v[i];
    return c;
}

bool try_add(vector<int> set, vector<int>& sub, int i, int curr, int target) {
    if (curr == target) {
        return true;
    }
    if (curr + set[i] > target) {
        return false;
    } else if (curr + sum(set, i) < target) {
        return false;
    } else {
        sub.push_back(set[i]);
        if (try_add(set, sub, i+1, curr+set[i], target)) {
            return true;
        } else {
            sub.pop_back();
            try_add(set, sub, i+1, curr, target);
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        int n; cin >> n;
        vector<int> A(n);
        for (int j = 0; j < n; j++) {
            cin >> A[j];
        }
        int d; cin >> d;

        vector<int> sub_A;
        bool can_sum = try_add(A, sub_A, 0, 0, d);
        
        cout << "Caso " << i << ": ";
        if (can_sum) {
            cout << "{";
            for (int j = 0; j < sub_A.size(); j++) {
                if (j == sub_A.size() - 1) {
                    cout << sub_A[j] << "}" << endl;
                } else {
                    cout << sub_A[j] << ",";
                }
            }
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
