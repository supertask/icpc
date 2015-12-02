#include<iostream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

char wb_table[100][100];

void draw_(int x, int y, int &n) {
	if (n % 2 == 0) wb_table[x][y] = 'W';
	else wb_table[x][y] = 'B';
}

int main() {
	int T,X,Y,N,w,k;
	cin >> T;
	rep(t,T) {
		//cout << "Case #" << (t+1) << ":" << endl;
		fill_n((char *) wb_table, sizeof(wb_table)/sizeof(char), '.');

		cin >> X >> Y;
		cin >> N;
		rep(n,2*N) {
			cin >> w >> k;
			rep(i,100) {
				if (k==0) draw_(i, w-1, n);
				else if(k==1) draw_(w-1, i, n); 
			}

			/*
			if (k == 0) {
				rep(i,100) {
					if (n % 2 == 0) {
						wb_table[i][w-1] = 'W';
					}
					else {
						wb_table[i][w-1] = 'B';
					}
				}
			}
			else if (k == 1) {
				rep(i,100) {
					if (n % 2 == 0) {
						wb_table[w-1][i] = 'W';
					}
					else {
						wb_table[w-1][i] = 'B';
					}
				}
			}
			*/
		}
		rep(y,Y) {
			rep(x,X) cout << wb_table[x][y];
			cout << endl;
		}
		cout << "#" << endl;
	}

	return EXIT_SUCCESS;
}
