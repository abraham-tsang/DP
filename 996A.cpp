#include <iostream>
#include <vector>

/*
int f996A(int input){
    std::vector<int> coins = {1, 5, 10, 20, 100};
    std::vector<int> dp;
    int additional = 0;
    if(input != input%100){
	additional = (input - input%100)/100;
	input = input%100;
    }
    for(int i = 0; i < input+1; i++){
	dp.push_back(-1);
    }
    dp[0] = 0;
    std::vector<int> temp;
    int min;
    for(int i = 0; i < input+1; i++){
	temp = {};
	for(int j = 0; j < 5; j++){
	    if(i-coins[j] < 0){
		break;
	    }
	    temp.push_back(dp[i-coins[j]]);
	}
	min = 99999;
        for(int j = 0; j < temp.size(); j++){
	    if(min > temp[j]){
		min = temp[j];
	    }
	}
	if(dp[i] == -1){
	    dp[i] = min + 1;
	}
    }
    return dp[input] + additional;
}
*/

int f996A_recursive(int input, std::vector<int> & coins, std::vector<int> & dp){
    //Base
    if(input == 0){
	return 0;
    }
    //Recursive
    else{
	if(dp[input] == -1){
	    int original = input;
	    int min = 99999;
	    int temp;
	    for(int i = 0; i < coins.size(); i++){
	        input = original;
	        if(input - coins[i] >= 0){
		    if(dp[input - coins[i]] != -1){
			temp = dp[input - coins[i]];
		    }
		    else{
		        temp = f996A_recursive(input - coins[i], coins, dp);
		    }
		    if(min > temp){
		        min = temp;
		    }
	        }
	    }
	    dp[input] = 1 + min;
	}
	return dp[input];
    }
}

int f996A(int input){
    std::vector<int> coins = {1, 5, 10, 20, 100};
    std::vector<int> dp;
    int additional = 0;
    if(input != input%100){
	additional = (input - input%100)/100;
	input = input%100;
    }
    for(int i = 0; i < input+1; i++){
	dp.push_back(-1);
    }
    dp[0] = 0;
    return f996A_recursive(input, coins, dp) + additional;
}


int main(){
    int input;
    std::cin >> input;
    std::cout << f996A(input);
}

