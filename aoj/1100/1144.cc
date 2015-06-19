/*
 * まだ
 */
#include<bits/stdc++.h>
#define dump(a) cout << (#a) << a << endl
using namespace std;

#define MAX_SIZE 21

int W,H;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int curing_map[MAX_SIZE][MAX_SIZE];
pair<int,int> start;
pair<int,int> goal;

int dfs(const int x, const int y) {
	for(int i=0; i<4; i++) {
		int ax, ay;
		int ax_back, ay_back;
		while(true) {
			ax = x + dx[i];
			ay = y + dy[i];
			if (ax >= H || ay >= W) { return; } //終了
			if (curing_map[ay][ax] == 1) { //障害物なら
				break;
			} 
			if (curing_map[ay][ax] == 3) { /*終了*/ } //ゴール
			ax_back = ax; ay_back = ay;
		}
		curing_map[ay][ax] = 0; //岩削除
		dfs();
	}
}

int main() {
	while(cin >> W >> H) {
		if (W == 0 && H == 0) { break; }	

		for(int y=0; y < H; y++) {
			for(int x=0; x < W; x++) {
				cin >> curing_map[y][x];
				if (curing_map[y][x] == 2) { start.first=x; start.second=y; }
				else if (curing_map[y][x] == 3) { goal.first=x; goal.second=y; }
			}
		}
		dfs(start.first, start.second);
	}

	return EXIT_SUCCESS;
}
