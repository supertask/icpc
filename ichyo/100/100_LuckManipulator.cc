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

int main() {
	int N,A,B,C,X;
	int Y[101];
	int check_cnt;
	int ii;
	
	while(cin >> N >> A >> B >> C >> X) 
	{
		if (N==0 && A==0 && B==0 && C==0 && X==0) { break; }
		ii=0;
		check_cnt=0;
		rep(i,N) {
			cin >> Y[i];
		}
		rep(i,10000) {
			if (check_cnt >= N) { break; }
			X = (A * X + B) % C;
			rep(j,N) {
				if (X == Y[j]) { //一致した数を出力する
					check_cnt++;
					ii=i;
				}
			}
		}
		if (check_cnt >= N) {
			cout << ii << endl;
		}
		else { cout << -1 << endl; }
	}


	return 0;
}
