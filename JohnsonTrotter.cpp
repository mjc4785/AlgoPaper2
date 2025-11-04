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

void swapItems(mobileNum& m, mobileNum& n){

	mobileNum temp = m;
	m = n;
	n = temp;
	//simple swap function through pass by ref

}

//function stolen from my paper1
void printvec(vector<mobileNum> m){
	int len = m.size();
	for(int i = 0; i<len; i++){
		printf("%d ", m[i].value);
	}
	printf("\n");
}

//created as void so no return necessary. Pass by referense for ease of use.
void johnsonTrotter(vector<mobileNum>& curr){

	//
	//START OF PERMUTATION CODE
	//	
	
	printvec(curr);

	while(true){
		int mobileVal = -1;
	    	int mobileIdx = -1;
	    	int n = curr.size();
		int primVal;
		int primIdx;
	
	    	for (int i = 0; i < n; i++) {			//loops through all variables in curr
	    	    int neighborIdx = i + curr[i].dir;		//tells us the neighbor's
	
	    	    if (neighborIdx >= 0 && neighborIdx < n) {
	    	        if (curr[i].value > curr[neighborIdx].value && curr[i].value > mobileVal) {
	    	            mobileVal = curr[i].value;
	    	            mobileIdx = i;
	    	        }
	    	    }
	    	}						//this will return us the Idx of the greatest mobile
								//element
		if (mobileIdx == -1){break;}			//if there is none, break. all done.
		int neighborIdx2 = mobileIdx + curr[mobileIdx].dir;
		swapItems(curr[mobileIdx], curr[neighborIdx2]); 	//swap the swappable neighbors
		
		primIdx = neighborIdx2;				//reassign stuff after swap for one more operation
		primVal = curr[primIdx].value;

		// loops through all numbers and flips the direction of the numbers greater than primVal
		for (int i = 0; i<n; i++){
			if (primVal < curr[i].value){
				curr[i].dir *= -1;
			}
		}
		printvec(curr);
	}


	//
	//END OF PERMUTATION CODE
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
