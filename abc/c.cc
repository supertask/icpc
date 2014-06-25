#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

vector<int> NGS;
int cnt = 0;
bool is_yes = false;


void saiki(int N) {
	if (N == 0) {
		is_yes = true;
		return;
	}
	else if (N < 0) {
		return;
	}
	else if (cnt > 100) {
		return;
	}
	else {
			int NN1,NN2,NN3;
			NN3 = N - 3;
			NN2 = N - 2;
			NN1 = N - 1;
	cout << N << endl;
	cout << "cnt " << cnt << endl;
			if (NN3 != NGS[0] && NN3 !=NGS[1] && NN3 !=NGS[2]) {
				saiki(NN3);
			}
			if (NN2 != NGS[0] && NN2 !=NGS[1] && NN2 !=NGS[2]) {
				saiki(NN2);
			}
			if (NN1 != NGS[0] && NN1 !=NGS[1] && NN1 !=NGS[2]) {
				saiki(NN1);
			}
		cnt++;
	}
}

int main() {
	int N;
	int NG1,NG2,NG3;
	
	cin >> N >> NG1 >> NG2 >> NG3;
	NGS.push_back(NG1);
	NGS.push_back(NG2);
	NGS.push_back(NG3);
	saiki(N);
	if (is_yes) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	cout << cnt << endl;

	return 0;
}
