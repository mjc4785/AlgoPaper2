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
	// Base case: combination is complete
    	if ((int)curr.size() == r) {
        	printvec(curr);
        	return;
    	}

    	// Try adding each next element
    	for (int i = start; i <= n; i++) {
        	curr.push_back(i);                 // include i
        	createCombo(i + 1, n, r, curr);  // recurse
        	curr.pop_back();                   // backtrack
    	}
}

void combination(int n, int r){
	vector<int> result;
	createCombo(1, n, r, result);
}

int main (){

	int n;	 							//init n
	printf("What is the number of permutations you'd like to try? (n): ");
	cin >> n;
	if (n < 0){printf("\nNumber must be greater than 0\n");}

	int r;
	printf("choose? (r): ");
	cin >> r;
	if (n < 0){printf("\nNumber must be greater than 0\n");}

	auto start = high_resolution_clock::now(); 			// start a timer for our algorithm(s)

	combination(n, r);

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start); 	//end the clock and find the time taken in ms
	printf("\n--Time taken: %ld ms--\n", duration.count());		// the time taken

	return 0;
}
