#include<bits/stdc++.h>
#define W_MAX 10
#define H_MAX 60

#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

char blocks[H_MAX][W_MAX];
int W,H;


void show() {
	rep(y,H) {
		rep(x,W) {
			cout << blocks[y][x];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	while(cin >> W >> H)
	{
		if (W == 0 && H == 0) { break; }
		fill_n((char *)blocks, sizeof(blocks)/sizeof(char), '.');
		rep(y,H) rep(x,W) { cin >> blocks[H-y-1][x]; }
		show();
	}

	return EXIT_SUCCESS;
}
