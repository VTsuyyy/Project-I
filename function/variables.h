
// Each Node contains point and next point for each path
struct node{
	int index;
	node *next = 0, *sub = 0;
	node(int i = 0){
		index = i;
	}
};

// Storage path as a state
struct status{
	int cost;
	int s[1001];
};

// Storage path as a tree structure
node *root;

// Save solution state for extend 
status *state[20000];

// numerical order and number of state for extend each time
int stt = 0, t = 10;

// Save the graph and cost
int n, weights[1001][1001] = {}, bestCost = 1e9, currCost = 0;

// Save sequence service for training
int bestSeq[1001] = {}, currSeq[1001] = {}, newSeq[1001] = {}, tempSeq[1001] = {};

// Check direct graph or undirect graph
bool direct;

// Check points has been visited or not
bool visited[1001];

// The weights of edge between points a th and b th in current sequence
#define edge(a, b) weights[currSeq[a]][currSeq[b]]

// Time executed
clock_t startTSP, endTSP;