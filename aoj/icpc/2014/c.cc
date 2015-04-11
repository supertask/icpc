#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };

class Dice {
	private:
		int num[6];

		void roll(FACE a, FACE b, FACE c, FACE d) {
			int tmp = num[a];
			num[a] = num[b];
			num[b] = num[c];
			num[c] = num[d];
			num[d] = tmp;
		}

	public:
		int height;
		Dice() {
			height = 0;
			num[TOP] = 1;
			num[BOTTOM] = 6;
			num[FRONT] = 3;
			num[BACK] = 4;
			num[RIGHT] = 5;
			num[LEFT] = 2;
		}

		void set(int top, int front) {
			if(num[RIGHT] == top || num[LEFT] == top)
				west();

			while(num[TOP] != top)
				north();

			while(num[FRONT] != front)
				right();
		}

		int operator[] (FACE f) const { return num[f]; }

		//基本これを用いて回転
		/*
		void north() { roll(TOP, BACK, BOTTOM, FRONT); }
		void east() { roll(TOP, LEFT, BOTTOM, RIGHT); }
		void west() { roll(TOP, RIGHT, BOTTOM, LEFT); }
		void south() { roll(TOP, FRONT, BOTTOM, BACK); }
		void right() { roll(BACK, RIGHT, FRONT, LEFT); }
		void left() { roll(BACK, LEFT, FRONT, RIGHT); }
		*/
		void roll_by(int dir) {
			if (dir == BACK) {
				roll(TOP, BACK, BOTTOM, FRONT);
			}
			else if (dir == RIGHT) {
			}
			else if (dir == LEFT) {
			}
			else if (dir == FRONT) {
			}
		}
};


const int MAX = 200;
const int CENTER = MAX / 2;
Dice field[MAX][MAX];


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dir[4] = {RIGHT,BACK,LEFT,FRONT};

void simulate_one_routeen(Dice& dice, int& x, int& y) {
	rep(i,4) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (field[y][x].height > field[ay][ax].height) {
			//中央の方が高い,転がる.
			dice. dir[i]
			north
			simulate_one_routeen();
		}
		else {
			//中央が低い,中央と同じ高さなら止まる.
			
		}
	}
}

int main(){
	int N;
	int top,front;

	while(cin >> N) {
		if (N == 0) { break; }
		fill_n((Dice *)field, sizeof(field)/sizeof(Dice), Dice()); //p, (x,y), value

		rep(i,N) {
			cin >> top >> front;
			Dice dice;
			dice.set(top,front);
			simulate_one_routeen(dice,CENTER,CENTER);
		}
	}


}

/*
   [How to]
   dice d;
   d.set(1,3);
   d.north();
   cout << d[TOP] << endl;//参照方法
 */
