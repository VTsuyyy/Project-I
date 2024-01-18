
// Include all library needed
#include "function/include.h"

int main(int argc, char * argv[]){
	
	input(argv[0]);

	initialize();

	// For graph small scale, use complete search path
    if(n < 20){
        complete_search(1);
	}

	// For large scale, must use more complicated algorithm
	else{
		
		greedy_algorithm();

		local_beam();
	}

	for(int l = 0; l <= n; l++){
		currSeq[l] = bestSeq[l];
	}

	heuristic();

	output();

}
