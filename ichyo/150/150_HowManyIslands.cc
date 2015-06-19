/* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp */
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
#define MAX_SIZE 50
#define dump(a) cerr << #a << "=" << (a) << endl

using namespace std;


int W,H;
int sima_cnt;
int sima_size;
int sima[MAX_SIZE+1][MAX_SIZE+1];
bool is_visit[MAX_SIZE+1][MAX_SIZE+1];

int dw[8] = {1,1,0,-1,-1,-1,0,1};
int dh[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int w, int h)
{
	if ( && is_visit[aw][ah]) { return; }
	is_visit[aw][ah]=true;

	rep(i,8) {
		int aw = w + dw[i];
		int ah = h + dh[i];
		if ((0<=aw && aw<W) && (0<=ah && ah<H))
		{
			//次の島を訊ねる条件
			if (sima[aw][ah]) { 
				sima_size++;
				dfs(aw,ah);
			}
		}
	}
}

int main() {
	while(cin >> W >> H) {
		if (W==0 && H==0) { break; }
		sima_cnt = 0;
		sima_size = 0;
		fill_n((int *)sima,sizeof(sima)/sizeof(int),0);

		rep(h,H) rep(w,W) cin >> sima[w][h];
		rep(h,H) rep(w,W) {
			sima_size = 0;
			if (sima[w][h] && !is_visit[w][h]) { sima_size++; }
			dfs(w,h);
			if (sima_size>0) {
				sima_cnt++;
			}
		}
		cout << sima_cnt << endl;
	}

	return 0;
}
