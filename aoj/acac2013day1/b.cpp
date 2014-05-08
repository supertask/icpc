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

int N,M;
int high[8];
bool is_visit[8];

vector<int> search(int i, bool is_left, vector<int> mover) {
	int ii = i;
	int back_high = high[i];
	if (is_left) { ii--; }
	else { ii++; }

	while (true) {
		if (ii < 0 || M < ii) { break; }
		if (is_visit[ii]) { break; }
		if (abs(high[ii] - back_high) >= 2) { break; } 
		else {
			//cout << high[ii] << " " << back_high << endl;
			if (is_left) { mover.push_back(ii+1); }
			else { mover.push_back(ii-1); }
			mover.push_back(ii);
		}
		back_high = high[ii];
		is_visit[ii] = true;
		if (is_left) { ii--; }
		else { ii++; }
	}
	return mover;
}

int main() {
	cin >> N >> M;

	rep(i,M) {
		is_visit[i] = false;
		cin >> high[i]; 	
	}

	rep(i,M) {
		vector<int> mover;
		mover = search(i,true,mover);
		mover = search(i,false,mover);
		rep(j,mover.size()) {
			cout << mover[j] << endl;
		}
		mover.clear();
		cout << endl;
	}


	return 0;
}
