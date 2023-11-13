#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int nrows;
    cin >> nrows;
    while (nrows != 0)
    {
        map<set<int>, int> combinations;
        for (int i = 0; i < nrows; i++)
        {
            set<int> courses;
            for (int j = 0; j < 5; j++)
            {
                int in;
                cin >> in;
                courses.insert(in);
            }
            combinations[courses] += 1;
        }
        map<int, int> amounts;
        for (auto &[key, value] : combinations)
        {
            amounts[value] += 1;
        }
        int max = amounts.end()->second;
        cout << amounts[amounts.end()->first] << endl;
    }
    return 0;
}