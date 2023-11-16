#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    stack <int> values;
    stack <int> mins;
    int entries;
    cin >> entries;
    int min = 1000000000;
    int removed;
    mins.push(min);
    values.push(0);
    for (int i = 0; i < entries; i++)
    {
        string entry;
        cin >> entry;
        int fun;

        if (entry == "PUSH")
        {
            cin >> fun;
            values.push(fun);
            if (fun <= mins.top())
            {
                mins.push(fun);
            }
        }
        else if (entry == "MIN")
        {
            if (mins.top() == 1000000000)
            {
                cout << "EMPTY" << "\n";
            }
            else
            {
                cout << mins.top() << "\n";
            }
        }
        else
        {
            if (values.top() == 0)
            {
                cout << "EMPTY" << "\n";
            }
            else
            {
                removed = values.top();
                values.pop();
                if (removed == mins.top())
                {
                    mins.pop();
                }
            }
        }
    }
    return 0;
}