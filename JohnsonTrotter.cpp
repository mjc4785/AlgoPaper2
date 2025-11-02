#include <iostream>
#include <cstdio>
#include<cmath>
#include <chrono>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std::chrono;

struct mobileNum{
	int value;		
	int dir;		// -1 for left 1 for right
};

//function stolen from my paper1
void printvec(vector<int> m){
	int len = m.size();
	for(int i = 0; i<len; i++){
		printf("%d ", m[i]);
	}
	printf("\n");
}

//created as void so no return necessary. Pass by referense for ease of use.
void johnsonTrotter(vector<mobileNum>& curr){

	//
	//START OF MIN-CHANGE CODE
	//
	


	//
	//END OF MIN-CHANGE CODE
	//
}

int main(){

	int n;	 							//init n
	printf("What is the number of permutations you'd like to try? (n): ");
	cin >> n;
	if (n < 0){printf("\nNumber must be greater than 0\n");}

	vector<mobileNum> curr;						//current list
	
	for (int i = 0; i<n; i++){
		mobileNum num;
		num.value = i+1;
		num.dir = -1;
		curr.push_back(num);
	}	

	auto start = high_resolution_clock::now(); 			// start a timer for our algorithm(s)

	johnsonTrotter(curr);					//this calls the minChange function

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start); 	//end the clock and find the time taken in ms
	printf("\n--Time taken: %ld ms--\n", duration.count());		// the time taken	

	return 0;
}
