#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 9 //8+1

int p_map[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int H,W,C;
int cnt;
vector<pair<int,int>> my_ryodos;

//現在制圧している領土の近傍
//vector<int> around_panes;

void dfs(int &x, int &y) {
	if (x >= W || y >= H ) { return; } //あふれ
	if () { return; }

	for(int i=0; i<4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		my_ryodos.push_back(make_pair(ax,ay));

		if (p_map[ay][ax] == p_map[y][x]) {
		}
		else { //色が一致しないとき，電圧かける
			change_all_color();
			cnt++;
		}

		dfs(ax,ay);
	}


}

int main() {
	while(cin >> H >> W >> C) {
		if (H == 0 && W == 0 && C == 0) { break; }

		for(int y=0; y<H; y++) {
			for(int x=0; x<W; x++) {
				cin >> p_map[y][x];
			}
		}


		//ここから
		for(int y=0; y<H; y++) {
			for(int x=0; x<W; x++) {
				//現在制圧している領土
				my_ryodos.clear();
				cnt=0;
				my_ryodos.push_back(make_pair(x,y));
				dfs(x,y,my_ryodos);
			}
		}
	}


	return EXIT_SUCCESS;
}
