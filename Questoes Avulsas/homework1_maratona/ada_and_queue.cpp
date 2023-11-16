#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int queries;
    cin >> queries;
    deque <int> tasks;
    bool reversed = false;
    string query;
    int task;
    for (int i = 0; i < queries; i++)
    {
        cin >> query;
        if (query == "back")
        {
            if (!tasks.empty())
            {
                if (reversed)
                {
                    cout << tasks.front() << "\n";
                    tasks.pop_front();
                }
                else
                {
                    cout << tasks.back() << "\n";
                    tasks.pop_back();
                }
            }
            else
            {
                cout << "No job for Ada?" << "\n";
            }
        }
        else if (query == "front")
        {
            if (!tasks.empty())
            {
                if (reversed)
                {
                    cout << tasks.back() << "\n";
                    tasks.pop_back();
                }
                else
                {
                    cout << tasks.front() << "\n";
                    tasks.pop_front();
                }
            }
            else
            {
                cout << "No job for Ada?" << "\n";
            }
        }
        else if (query == "reverse")
        {
            reversed = !reversed;
        }
        else if (query == "push_back")
        {
            cin >> task;
            if (reversed)
            {
                tasks.push_front(task);
            }
            else
            {
                tasks.push_back(task);
            }
        }
        else if (query == "toFront")
        {
            cin >> task;
            if (reversed)
            {
                tasks.push_back(task);
            }
            else
            {
                tasks.push_front(task);
            }
        }
    }
    return 0;
}