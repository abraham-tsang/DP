#include <iostream>
#include <vector>

int f189A(int n, int a, int b, int c){
    std::vector<int> dp;
    std::vector<int> abc;
    abc.push_back(a);
    abc.push_back(b);
    abc.push_back(c);
    for(int i = 0; i < n+1; i++){
	dp.push_back(-1);
    }
    int temp;
    int max;
    dp[c] = 1;
    for(int i = c+1; i < n+1; i++){
	max = 0;
        for(int j = 0; j < abc.size(); j++){
	    temp = i - abc[j];
	    if(temp < 0){
	        if(dp[temp] != -1){
	            if(max < dp[temp]){
	    	    max = dp[temp];
	            }
	        }
	    }
	}
	dp[i] = 1 + max;
    }
    return dp[n];
}
