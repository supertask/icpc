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

int cx,cy,cnt;

int main() {
	int N,M;
	while(cin >> N && N) 
	{
		int light[21][21];
		int x,y;
		rep(j,21) {
			rep(i,21){ light[i][j] = false; }
		}
		rep(i,N) {	
			cin >> x >> y;
			light[x][y] = true;
		}
		cin >> M;
		char angle;
		int move;
		cx=10,cy=10,cnt=0;
		rep(i,M) {
			cin >> angle >> move;
			if (angle == 'N') {
				rep(i,move) {
					if (light[cx][cy+i+1]) { 
						cnt++; 
						light[cx][cy+i+1] = false; 
					}
				}
				cy += move;
			}
			else if (angle == 'E') { //東
				rep(i,move) {
					if (light[cx+i+1][cy]) {
						cnt++; 
						light[cx+i+1][cy] = false; 
					}
				}
				cx += move;
			}
			else if (angle == 'S') { //南
				rep(i,move) {
					if (light[cx][cy-i-1]) {
						cnt++;
						light[cx][cy-i-1] = false; 
					}
				}
				cy -= move;
			}
			else if (angle == 'W') { //西
				rep(i,move) {
					if (light[cx-i-1][cy]) {
						cnt++;
						light[cx-i-1][cy] = false; 
					}
				}
				cx -= move;
			}
		}
		if (cnt == N) { cout << "Yes" << endl; }
		else { cout << "No" << endl; }
	}

	return 0;
}
