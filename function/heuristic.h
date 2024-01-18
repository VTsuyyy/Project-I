

bool directed(int bonus = 0, int begin = 0, int num = 1000){
	// For each three points i th, j th, k th in current sequence
	for(int i = begin; i < n; ++i){
		for(int j = i+2; j < n; ++j){
			for(int k = j; k < n; ++k){
				// If convert two ways (i+1 -> j-1) and (j -> k) has the cost in acceptance threshold
				// It mean (i, i+1) + (j-1, j) + (k, k+1) + bonus have more cost than (i, j) + (k, i+1) + (j-1, k+1)
				// Bonus accept new solution maybe worse than previous solution in acceptance threshold
				if(edge(i, i+1) + edge(j-1, j) + edge(k, k+1) + bonus > edge(i, j) + edge(k, i+1) + edge(j-1, k+1)){
					for(int l = 0; l <= n; ++l){
                        newSeq[l] = currSeq[l];
                    }
                    // Convert these two ways
                    for(int l = 0; l <= k-j; ++l){
                        tempSeq[l] = newSeq[j+l];
                    }
                    for(int l = k; l > i+(k+1-j); --l){
                        newSeq[l] = newSeq[l-(k-j+1)];
                    }
                    for(int l = 0; l <= k-j; ++l){
                        newSeq[i+l+1] = tempSeq[l];
                    }
                    num -= add_path(newSeq);
                    if(num == 0){
                        return true;
                    }
				}
			}
		}
	}
    return false;
}

bool undirected(int bonus = 0, int begin = 0, int num = 1000){
	// For each two points i th, j th in current sequence
    for(int i = begin; i < n; ++i){
        for(int j = i + 3; j < n; ++j){
			// If reverse direction from i+1 to j-1 has the cost in acceptance threshold
            // It mean (i, i+1) + (j-1, j) + bonus have more cost than (i, j-1) and (i+1, j)
			// Bonus accept new solution maybe worse than previous solution in acceptance threshold
			if(edge(i, i+1) + edge(j-1, j) + bonus > edge(i, j-1) + edge(i+1, j)){
                for(int l = 0; l <= n; ++l){
                    newSeq[l] = currSeq[l];
                }
				// Reverse directions from point i+1 to j-1
                for(int k = 1; k <= (j-i) / 2; ++k){
                    int temp = newSeq[i + k];
                    newSeq[i + k] = newSeq[j - k];
                    newSeq[j - k] = temp;
                }
                num -= add_path(newSeq);
                if(num == 0){
                    return true;
                }
            }
        }
    }
    return directed();
}

// Heuristic find the solution in which new solutions have the cost in acceptance threshold
bool heuristic(int bonus = 0, int begin = 0){
	// Choose heuristic algorithm depend on directed graph or undirected graph
    if(direct)
        return directed(bonus, begin);
    else
        return undirected(bonus, begin);
}