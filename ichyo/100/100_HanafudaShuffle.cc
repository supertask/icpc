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
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl

using namespace std;

int cards[52];

int main() {
	int N,R; 
	int P,C;

	while(cin >> N >> R) {
		if (N == 0 && R == 0) break;
		//初期化
		rep(i,52) {
			cards[i] = 0;			
		}
		rep(i,N) {
			cards[i] = i+1;
		}


		//シャッフル
		vector<int> cards_p,cards_c;
		int center=0;
		rep(r,R) {
			cin >> P >> C;

			//コピー
			center = N-(P-1);
			REP(c,center-C,center) {
				cards_c.push_back(cards[c]);
			}
			REP(p,center,N) {
				cards_p.push_back(cards[p]);
			}
			
			//ペースト
			center = N-C;
			REP(p,center-(P-1),center) {
				cards[p] = cards_p.front();
				cards_p.erase(cards_p.begin());
			}
			REP(c,center,N) {
				cards[c] = cards_c.front();
				cards_c.erase(cards_c.begin());
			}
		}

		cout << cards[N-1] << endl;			
		
	}

	return 0;
}
