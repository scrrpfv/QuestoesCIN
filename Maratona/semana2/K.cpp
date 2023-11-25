#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    string lowerstr;
    vector<string> solutions;
    
    for (auto l : str){
    	lowerstr += tolower(l);
    	}
    	
    
    for (int i = 0; i < lowerstr.size(); i++){
   		char l1 = lowerstr[i];
   		char l2 = lowerstr[i + 1];
   		string a1;
   		a1 = l1;
   		string a2;
   		a2 = l2;
    	if (a1.compare("s") == 0 && a2.compare("s")){
    		string temp = lowerstr;
    		string B = "B";
    		temp.replace(i-1, 2, B);
    		solutions.push_back(temp);
    		}
    	}
    cout << solutions[0] << "\n" << solutions [1] << solutions[2] << "\n";
    cout << "ue";
    return 0;
}
