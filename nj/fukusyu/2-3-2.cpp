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
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_    str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
using namespace std;

int main() {
	int N,Q;
	vector<int> S(100000);

	cin >> N;
	rep(i,N) {
		cin >> S[i];
	}

	cin >> Q;
	int count=0;
	int T;
	sort(all(S));
	rep(i,Q) {
		cin >> T;
		if (binary_search(all(S),T)) {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}
