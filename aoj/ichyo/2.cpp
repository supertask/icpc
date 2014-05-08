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


int N,R;
int P,C;
int cards[50+1];
int c_cards[50+1];
int p_cards[50+1];

void show() {
	/*
	rep(i,N) {
		cout << c_cards[i];
	}
	cout << endl;
	*/
	rep(i,N) {
		cout << cards[i];
	}
	cout << endl;
}

void block_swap() {
	int begin_p = N-P+2;
	int end_p = N+1;
	int begin_c = begin_p-C;
	int end_c = N-P+2;
	printf("p: %d %d\n",begin_p,end_p);
	printf("c: %d %d\n",begin_c,end_c);

	REP(i,begin_p,end_p) {
		p_cards[i] = cards[i];
	}
	REP(i,begin_c,end_c) {
		c_cards[i] = cards[i];
	}
	show();
	REP(i,end_p-C,end_p) {
		cards[i] = c_cards[i];
	}
	REP(i,begin_c,begin_c+P-1) {
		cards[i] = p_cards[i];
	}
	//show();
}

int main() {
	while(true) {
		cin >> N >> R;
		cout << N << endl;
		if (N == 0 && R == 0) { break; }
		rep(i,N) {
			cards[i] = i+1;
		}
		rep(i,R) {
			cin >> P >> C;
			block_swap();
		}
		cout << cards[N] << endl;
	}

	return 0;
}
