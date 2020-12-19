#include <iostream>
#include <vector>

/*
int f996A(int input){
    std::vector<int> coins = {1, 5, 10, 20, 100};
    std::vector<int> dp;
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
    return dp[input];
}
*/

int f996A(int input){
    std::vector<int> coins = {1, 5, 10, 20, 100};
    std::vector<int> dp;
    int size = input;
    if(input > 101){
	size = 101;
    }
    for(int i = 0; i < size; i++){
	dp.push_back(-1);
    }
    dp[0] = 0;
    std::vector<int> temp;
    int min;
    int it = 0;
    for(int i = 0; i < input+1; i++){ // change i to fit into 101
	temp = {};
	for(int j = 0; j < 5; j++){
	    if((i-coins[j]) % 101 < 0){
		break;
	    }
	    temp.push_back(dp[(i-coins[j]) % 101]);
	}
	min = 99999;
        for(int j = 0; j < temp.size(); j++){
	    if(min > temp[j]){
		min = temp[j];
	    }
	}
	if(i % 101 == 0 && it == 0){
	    it++;
	}
	else{
	    dp[i % 101] = min + 1;
	}
    }
    return dp[input%101];
}

/*
int main(){
    std::cout << f996A(1000000000);
}
*/
