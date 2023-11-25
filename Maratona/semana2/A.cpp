#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    double x1, y1, x2, y2;
    
    cin >> T;
    
    for (int i = 0; i < T; i++){
    	cin >> x1 >> y1 >> x2 >> y2;
    	double a = (x1*y2 - x2*y1)/(x1*x2*x2 - x1*x1*x2);
    	double b = y1/x1 - a*x1;
    	double d = (-1*b)/(a);
    	cout << setprecision(16) << d << "\n";
    	}
    
    return 0;
}
