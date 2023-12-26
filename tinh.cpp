
// Include all library needed
#include "include.h"

int main(){
    cin >> n;
    for(int i = 0; i <= n; ++i){
        cin >> currSeq[i];
    }
    input();
    cout << cal_cost(currSeq);
}


