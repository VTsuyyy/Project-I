
// N
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

//
node *root;

//
status *state[20000];

//
int stt = 0, t = 10;

//
int n, weights[1001][1001] = {}, bestCost = 1e9, currCost = 0;

//
int bestSeq[1001] = {}, currSeq[1001] = {}, newSeq[1001] = {}, tempSeq[1001] = {};

//
bool direct;

// Check points has been visited or not
bool visited[1001];

// The weights of edge between points a th and b th in current sequence
#define edge(a, b) weights[currSeq[a]][currSeq[b]]

//
clock_t startTSP, endTSP;