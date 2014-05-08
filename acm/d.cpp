#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_    str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
#define MAX_HIGH 1005
using namespace std;


int main() {
	int M,N;

	while (true) {
		cin >> M >> N;
		if (M == 0 && N == 0) { break; }
		int maps[MAX_HIGH][MAX_HIGH];
		rep(y,MAX_HIGH) {
			rep(x,MAX_HIGH) {
				cout << maps[x][y] << " ";
			}
			cout << endl;
		}
	}

	

	return 0;
}
