#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
#define MAX_SIZE 10000

using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;

	int t=0;
	int back_time=0;
	bool is_break = false;
	int ans=0;
	while(true) {
		if (t > MAX_SIZE) { break; }
		if (is_break) { break; }
		int time = 60*t + c;

		for(int i=0; i<time; i+=(a+b)) {
			if (i <= time && time <= i+a) {
				ans = time;
				is_break = true;
				break;
			}
		}
		back_time = time;
		t++;
	}
	if (is_break) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}


	return EXIT_SUCCESS;
}
