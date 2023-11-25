#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n_classes;
    cin >> n_classes;
    vector<int> classes;
    vector<int> thresholds;
    for (int i = 0; i < n_classes; i++){
    	int clas;
    	cin >> clas;
    	classes.push_back(clas);
    	}
    int n_days;
    cin >> n_days;
    for (int i = 0; i < n_days; i++){
    	int threshold;
    	cin >> threshold;
    	thresholds.push_back(threshold);
    	}
    
    sort(classes.begin(), classes.end());
    
    for (int i = 0; i < n_days; i++){
    	int sum = 0;
    	int n = 0;
    	while (sum < thresholds[i]){
    		sum += classes[n];
    		n += 1;
    		}
    	cout << sum << n << "\n";
    	}
    
    return 0;
}
