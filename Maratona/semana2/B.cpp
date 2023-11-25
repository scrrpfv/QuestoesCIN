#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
    	int w, d, h, xl, yl, xp, yp;
    	cin >> w >> d >> h;
    	cin >> xl >> yl;
    	cin >> xp >> yp;
    	
    	int sa = xl + xp;
    	int sb = yl + yp;
    	int sc = 2*w - sa;
    	int sd = 2*d - sb;
    	
    	int sx = min(sa, sc);
    	int sy = min(sb, sd);
    	int total;
    	
    	if (sx < sy){
    		total = h + sx + abs(yl - yp);
    		}
    	else{
    		total = h + sy + abs(xl - xp);
    		}
    	cout << total << "\n";
    	}
    
    return 0;
}
