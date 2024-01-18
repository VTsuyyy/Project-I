
void greedy_algorithm(int b = 1){
	// A path begin and end at point b 
	int k = -1, k1 = n + 1;
	currSeq[--k1] = b;
	currSeq[++k] = b;
	visited[b] = true;
	while(k + 1 < k1){

		int tmp, mn = 1e9, check = 0;
		// For all points not visited
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				// Check to find the point nearest
				if(weights[currSeq[k]][i] < mn){
					mn = weights[currSeq[k]][i];
					tmp = i;
					check = 0;
				}
				if(weights[i][currSeq[k1]] < mn){
					mn = weights[i][currSeq[k1]];
					tmp = i;
					check = 1;
				}
			}
		}
		// Visit that points
		visited[tmp] = true;
		if(check){
			currSeq[--k1] = tmp;
		}
		else{
			currSeq[++k] = tmp;
		}
	}
	int j = 0, l = 0;
	for(j; j <= n; j++){
		if(currSeq[j] == 1){
			break;
		}
	}
	// Save the current path
	bestCost = cal_cost(currSeq);
	for(l; l + j <= n; ++l){
		bestSeq[l] = currSeq[l + j];
	}
	for(l = 0; l <= j; ++l){
		bestSeq[l+(n-j)] = currSeq[l];
	}
}