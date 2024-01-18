#include<bits/stdc++.h>
using namespace std;
int s[1001][1001] = {};
int main(int argc, char * argv[]) {
    int n, a, b;
    bool c;
    cout << "Choose the number of vertexs to create: ";
    cin >> n;
    cout << "Choose the number of maximal length: ";
    cin >> a;
    cout << "Choose the number of minimal length: ";
    cin >> b;
    cout << "Choose directed (1) or undirected graph (0): ";
    cin >> c;
    if(a <= b || b <= 0){
        cout << "ERROR";
        return 0;
    }
    a -= b;
    string str = argv[0];
    str = str.substr(0, str.size()-16) + "input\\" + "inp" + to_string(n) + ".txt";
	freopen(&str[0], "w", stdout);
    cout << n << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) s[i][j] = 0;
            else if(!c && j < i) s[i][j] = s[j][i];
            else s[i][j] = rand() % a + b;
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    
}