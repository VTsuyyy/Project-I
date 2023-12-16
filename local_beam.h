
// Choose best k-state and generate new path from this k-state
void local_beam(){
    
    startTSP = clock();

    heuristic(10);
    sort(state, state + 20000, [](status *a, status *b)->bool{
        return a->cost < b->cost;
    });
    int i = 0, a = 10;
    for(int test = 1; test < 50000; test++){
        ++i;
        for(int l = 0; l <= n; l++){
            currSeq[l] = state[i]->s[l];
        }
        heuristic(2 + state[i]->cost / 150);
        state[i]->cost = 1e6;
        // cout << bestCost << " " << stt << endl;
        if(test > 20 || t > 5){
            a = 100;
        }
        if(stt < i + 5000 || test % a == 0){
            i = 0;
            stt = 20000;
            sort(state, state + 20000, [](status *a, status *b)->bool{
                return a->cost < b->cost;
            });
        }
    	endTSP = clock();
        if(endTSP - startTSP > t * 1000)
            break;
    }

}