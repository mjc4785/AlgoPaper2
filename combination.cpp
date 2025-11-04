#include <iostream>
#include <cstdio>
#include<cmath>
#include <chrono>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std::chrono;

//function stolen from my paper1
void printvec(vector<int> m){
	int len = m.size();
	for(int i = 0; i<len; i++){
		printf("%d ", m[i]);
	}
	printf("\n");
}

void createCombo(int start, int n, int r, vector<int>& curr){
    	if ((int)curr.size() == r) {				//base case. comboniation is done
        	printvec(curr);
        	return;
    	}

    	for (int i = start; i <= n; i++) {
        	curr.push_back(i);                 		// include i
        	createCombo(i + 1, n, r, curr);  		// recurse
        	curr.pop_back();                   		// backtrack
    	}
}

void combination(int n, int r){
	vector<int> result;						//intermediate function for initial recursion
	createCombo(1, n, r, result);					//abstraction helped me understand parameters 
}

int main (){

	int n;	 								//init n permutations num
	printf("What is the number of permutations you'd like to try? (n): ");	
	cin >> n;
	if (n < 0){printf("\nNumber must be greater than 0\n");}

	int r;									//choose number
	printf("choose? (r): ");
	cin >> r;
	if (n < 0){printf("\nNumber must be greater than 0\n");}

	auto start = high_resolution_clock::now(); 			// start a timer for our algorithm(s)

	combination(n, r);						//call our created function

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start); 	//end the clock and find the time taken in ms
	printf("\n--Time taken: %ld ms--\n", duration.count());		// the time taken

	return 0;
}
