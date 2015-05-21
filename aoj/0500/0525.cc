#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
#define MAX_R 10
#define MAX_C 10000

using namespace std;

bool sembei_map[MAX_R][MAX_C];

int main()
{
	int R,C;
	bool cell;

	while(cin >> R >> C) {
		if (R==0&&C==0) { break; }

		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				cin >> sembei_map[i][j];
			}
		}

		//ここから全パターンを試す
		int all_ans=0;
		for(int pat=0; pat<(1<<R); pat++) { //pattern=1024
			int ans = 0;
			for(int r=0; r<MAX_R; r++) { //R=10
				int one = 0;
				for(int c=0; c<MAX_C; c++) {
					one += ((pat>>1) & 1) ^ sembei_map[r][c];
				}
				ans += max(one, R-one);				
			}
			all_ans(all_ans,ans);
		}

		

	}
}
