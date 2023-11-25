#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
    string str1;
    string str2;
    cin >> str1 >> str2;
    string concat = str1 + str2;
    sort(concat.begin(), concat.end());
    cout << concat << "\n";
    }
    
    return 0;
}
