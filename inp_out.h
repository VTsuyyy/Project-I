
void input(){
	cout << "Choose the number of points: ";
	cin >> n;
	string s = "inp" + to_string(n) + ".txt";
	cout << "Choose time limit: ";
	cin >> t;
    freopen(&s[0], "r", stdin);

	// Input the weights from i th point to j th point (complete graph with n points)
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &weights[i][j]);
		}
	}
}

// Output all performance information
void output(){
	cout << endl << "Type: ";
	direct ? cout << "direct" : cout << "undirect";
	cout << " graph" << endl;
	cout << "Time performed: " << endTSP - startTSP << "(ms)" << endl;
    cout << "Lowest cost: " << bestCost << endl;
	cout << "Path: ";
	for(int k = 0; k <= n; ++k){
		cout << bestSeq[k] << " ";
	}
	// cout << endl;
	// for(int k = 0; k <= n; ++k){
	// 	cout << currSeq[k] << " ";
	// }
}

