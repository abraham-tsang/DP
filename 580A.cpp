#include <iostream>
#include <vector>

/*
int f508A(int size, std::vector<int> input){
    std::vector<int> dp;
    for(int i = 0; i < size; i++){
	dp.push_back(-1);
    }
    int max = -1;
    for(int i = 0; i < size; i++){
	if(i == 0){
	    dp[i] = 1;
	}
	else{
	    if(input[i] >= input[i-1]){
		dp[i] = dp[i-1] + 1;
	    }
	    else{
		dp[i] = 1;
	    }
	}
    }
    for(int i = 0; i < size; i++){
	if(max < dp[i]){
	    max = dp[i];
	}
    }
    return max;
}
*/

int f508A_recursive(int & size, std::vector<int> & input, std::vector<int> & dp, int & it){
    //Base
    if(it == 0){
	dp[0] = 1;
    }
    //Recursive
    else{
	int next = it - 1;
	f508A_recursive(size, input, dp, next);
	if(input[it] >= input[it-1]){
	    dp[it] = dp[it-1] + 1;
	}
	else{
	    dp[it] = 1;  
        }
    }
}

int f508A(int size, std::vector<int> input){
    std::vector<int> dp;
    for(int i = 0; i < size; i++){
	dp.push_back(-1);
    }
    int start = size - 1;
    f508A_recursive(size, input, dp, start);
    int max = -1;
    for(int i = 0; i < size; i++){
	if(max < dp[i]){
	    max = dp[i];
	}
    }
    return max;
}


int main(){
    int size;
    std::vector<int> input;
    std::cin >> size;
    int temp;
    for(int i = 0; i < size; i++){
	std::cin >> temp;
	input.push_back(temp);
    }
    std::cout << f508A(size, input);
}

