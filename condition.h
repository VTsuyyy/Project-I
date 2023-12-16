// calculate the current sequence's cost
int cal_cost(int *sequence){
	int cost = 0;
	for(int k = 0; k < n; ++k){
		cost += weights[*(sequence + k)][*(sequence + k + 1)];
	}
	return cost;
}



// Check if the current sequence has already been taken
// If it has already been taken return false, otherwise return true
bool check_path(int *sequence){

	// The path is storaged as a tree with multiple branches
	node *temp = root;
	int i = 1;

	// Find the way in the tree
	while(1){

		while(temp->next){
			if(temp->index == sequence[i]){
				break;
			}
			temp = temp->next;
		}

		if(temp->index == sequence[i]){
			++i;
			temp = temp->sub;
		}

		else{
			break;
		}
	}

	// If there is a path like this, return false
	if(i >= n){
		return false;
	}

	// Else, continue add the path in new branch 
	temp->next = new node(sequence[i++]);
	temp = temp->next;
	for(i; i < n; i++){
		temp->sub = new node(sequence[i]);
		temp = temp->sub;
	}

	// End path by leaf node and return true
	temp->sub = new node();
	return true;
}



// Add new path as a state
void add_path(int *sequence){

	// Check if path already exists   
	if(check_path(sequence)){

		// If path not exist, add it as a state
		status *temp = state[--stt];
		temp->cost = cal_cost(sequence);
		for(int l = 0; l <= n; ++l){
			temp->s[l] = sequence[l];
		}

		// If new path better than current best solution, assign it as a best solution
		if(temp->cost < bestCost){
			bestCost = temp->cost;
			for(int l = 0; l <= n; ++l){
				bestSeq[l] = temp->s[l];
			}
		}
	}
}