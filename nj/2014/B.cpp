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
#define all(c) (c).begin(), (c).end()

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

int N;
int H,M,MM;


int main() {

	while (cin >> N) 
	{
		if (N == 0) { break; }
		int l_count = 0;
		int d_count = 0;
		int m_count = 0;
		int ll_count = 0;
		int dd_count = 0;
		int mm_count = 0;
		rep(i,N) {
			scanf("%d%*c%d%d",&H, &M, &MM);
			int diff;
			if ((MM - M) >= 0) {
				diff = MM - M;
			}
			else {
				diff = 60 - M + MM;
			}
			if (11 <= H && H <= 14) { 
				if (diff <= 8) { l_count++; }
				ll_count++;
			}
			else if (18 <= H && H <= 20) { 
				if (diff <= 8) { d_count++; }
				dd_count++;
			}
			else if (21 <= H && H <= 1) { 
				if (diff <= 8) { m_count++; }
				mm_count++;
			}
		}
		//rep_end
		if (ll_count == 0) {
			cout << "lunch no guest" << endl;
		}
		else {
			cout << "lunch " << (100 * l_count) / ll_count << endl;
		}
		if (dd_count == 0) {
			cout << "dinner no guest" << endl;
		}
		else {
			cout << "dinner " << (100 * d_count) / dd_count << endl;
		}
		if (mm_count == 0) {
			cout << "midnight no guest" << endl;
		}
		else {
			cout << "midnight " << (100 * m_count) / mm_count << endl;
		}
		
	}

	return 0;
}
