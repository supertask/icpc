#include <iostream>
using namespace std;

int main() {
	int T;
	int gx,gy;
	int mataNumber;
	int x1,y1,x2,y2;
	
	cin >> T;
	for (int t=0; t<T; t++)
	{
		cin >> gx >> gy;
		cin >> mataNumber;
		
		bool bridge[gx+1][gy+1];
		bool leftBridge[gx+1][gy+1];
		bool topBridge[gx+1][gy+1];
		int map[gx+1][gy+1];
		for (int i=0; i<=gy; i++) {
			for (int ii=0; ii<=gx; ii++) {
				bridge[ii][i] = false;
				leftBridge[ii][i] = false;
				topBridge[ii][i] = false;
				map[ii][i] = 0;
			}
		}
		map[0][0] = 1; //最初は1
		
		
		for (int i=0; i < mataNumber; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			bridge[x1][y1] = true;
			bridge[x2][y2] = true;
		}
		
		for (int i=0; i<=gy; i++) {
			for (int ii=0; ii<=gx; ii++) {
				if (0 <= ii-1) {
					if (bridge[ii-1][i] && bridge[ii][i]) {
						leftBridge[ii][i] = true;
					}
				}
				
				if (0 <= i-1) {
					if (bridge[ii][i-1] && bridge[ii][i]) {
						topBridge[ii][i] = true;
					}
				}
			}
		}
		for (int i=0; i<=gy; i++) {
			for (int ii=0; ii<=gx; ii++) {
				if (0 <= ii-1) {
					if (!leftBridge[ii][i]) {
						map[ii][i] += map[ii-1][i];
					}
				}
				if (0 <= i-1) {
					if (!topBridge[ii][i]) {
						map[ii][i] += map[ii][i-1];
					}
				}
			}
		}
		//最後の出力
		if (map[gx][gy] == 0) {
			cout << "Miserable Hokusai!" << endl;
		}
		else {
			cout << map[gx][gy] << endl;
		}
		
	}

	return 0;
}


