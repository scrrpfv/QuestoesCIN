#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        int n; cin >> n;
        if (n == 0) {
            cout << "Caso " << i << ": 0=0" << endl;
        } else {
            vector<int> coins(n+1);
            for (int j = 1; j <= n; j++) {
                cin >> coins[j];
            }

            vector<int> F(n+1);
            F[0] = 0;
            F[1] = coins[1];
            vector<int> s;
            for (int j = 2; j <= n; j++) {
                if (coins[j] + F[j-2] > F[j-1]) {
                    F[j] = coins[j] + F[j-2];
                } else {
                    F[j] = F[j-1];
                }
            }

            for (int j = n; j > 0; j--) {
                if (F[j] == F[j-1] + coins[j]) {
                    s.push_back(coins[j]);
                } else if (F[j] == F[j-2] + coins[j]) {
                    s.push_back(coins[j]);
                    j--;
                }
            }

            cout << "Caso " << i << ": ";
            for (int j = s.size() - 1; j >= 0; j--) {
                if (j > 0) {
                    cout << s[j] << "+";      
                } else {
                    cout << s[j] << "=";
                }
            }
            cout << F[n] << endl;
        }
    }
    return 0;
}