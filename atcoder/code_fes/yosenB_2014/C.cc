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

using namespace std;

int main() {
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	sort(ALL(s1));
	sort(ALL(s2));
	sort(ALL(s3));

	int N2 = s3.size();
	bool is_ok = true;
	rep(i,N2) {
		if (s1.front() == s3.front()) {
			s1.erase(s1.begin());
			s3.erase(s3.begin());
		}
		else if (s2.front() == s3.front()) {
			s2.erase(s2.begin());
			s3.erase(s3.begin());
		}
		else {
			is_ok = false;
			break;
		}
	}
	if (is_ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}
