
// Complete search find all solutions and choose the best solution
// Use Alpha-beta prunning to cut the solution in which cannot be the best solution
void complete_search(int k){
	
	int currCity = currSeq[k - 1];

	// If find a new solution
	if(k == n){
		// Check if the solution is better than the current best solution
		if(currCost + weights[currCity][1] < bestCost){
			// Save the new solution as the current best solution
            bestCost = currCost + weights[currCity][1];
            for(int i = 0; i <= n; i++){
                bestSeq[i] = currSeq[i];
			}
        }
		return;
	}

	// Check all points if not visited
	for(int i = 2; i <= n; ++i){
		if(!visited[i]){
			int cost = weights[currCity][i];

			// Check the condition to cut the branch in which not feasible
			if(currCost + cost + (n-k) < bestCost){
				// If it is feasible, come this point
				currSeq[k] = i;
				currCost += cost;
				visited[i] = 1;
				complete_search(k + 1);
				visited[i] = 0;
				currCost -= cost;
			}
		}
	}
}
