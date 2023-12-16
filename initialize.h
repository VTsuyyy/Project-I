
void initialize(){

    direct = false;

	for(int i = 0; i <= n; i++){
    	// Check this graph is directed or undirected
		if(weights[i][1] != weights[1][i]){
			direct = true;
		}

        // Renew global array
        visited[i] = false;
        currSeq[i] = 0;
	}

    // Create empty state
    for(int i = 0; i < 20000; ++i){
        state[i] = new status();
        state[i]->cost = 1e6;
    }

    // Renew global variables
	currSeq[0] = 1;
	currSeq[n] = 1;
	root = new node();
	root->index = 1;
    stt = 20000;
}