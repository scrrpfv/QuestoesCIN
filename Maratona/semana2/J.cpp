#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    int x;
    
    cin >> t;
    
    for (int i = 0; i < t; i++){
    	cin >> x;
		cout << 1 << x << ", ";
    	
    	}
    return 0;
}

/*
1  2  3  4  5  6  7  8  9  10
11 12 13 14 15 16 17 18 19 20
   22 23    25 26    28 29   
      33       36       39 40
         44 45 46 47 48 49 50
            55 56    58 59   
               66       69 70
                  77 78 79 80
                     88 89   
                        99 100

1 +
                             
11 12 13 14 15 16 17 18 19 20
   22 23    25 26    28 29   
      33       36       39 40
         44 45 46 47 48 49 50
            55 56    58 59   
               66       69 70
                  77 78 79 80
                     88 89   
                        99 100
*/
