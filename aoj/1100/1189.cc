/* D 素数洞窟: AC */
#include<bits/stdc++.h>
#define dump(a) cout << (#a) << (a) << endl
using namespace std;

const int MAX_OF_MAP = 1000+500;
const int CENTER = MAX_OF_MAP/2;
enum ANGLES {UP,LEFT,BOTTOM,RIGHT};
const int PRIME_MAX = 1000000+1;
bool is_prime[PRIME_MAX];
vector<pair<int,int> > MOVE_POINT_OF_ANGLE(4);
vector<pair<int,int> > LEFT_POINT_OF_ANGLE(4);

int caves[MAX_OF_MAP][MAX_OF_MAP];
pair<int,int> memo_caves[MAX_OF_MAP][MAX_OF_MAP];
//vector<vector<int> > caves(MAX_OF_MAP,vector<int>(MAX_OF_MAP, 0));
//vector<vector<pair<int,int> > > memo_caves(MAX_OF_MAP,vector<pair<int,int> >(MAX_OF_MAP, make_pair(0,0)));


void show()
{
	int block = 7;
	for(int y=CENTER+block; y>=CENTER-block; y--)
	{
		for(int x=CENTER-block; x<=CENTER+block; x++)
		{
			cout << caves[y][x] << "\t";
		}
		cout << endl;
	}
}


const int bottom_x[3] = {-1,0,1};
const int bottom_y[3] = {-1,-1,-1};
/*
 * メモ化再起でO(2^sqrt(M))からO(M)に変更する
 */
// First=最大の洞窟の数, Second=最後に通過した洞窟番号
pair<int,int> search_to_bottom(int &x, int &y)
{
	int num = caves[y][x];
	if (num == 0) { return make_pair(0,0); }
	if (memo_caves[y][x].first != -1) { return memo_caves[y][x]; }

	pair<int,int> res_pair(0,0);
	for(int i=0; i<3; i++) {
		int ax = x + bottom_x[i];
		int ay = y + bottom_y[i];
		pair<int,int> a_pair;
		a_pair = search_to_bottom(ax,ay);
		res_pair = max(res_pair,a_pair);
	}

	if (is_prime[num]) { 
		if (res_pair.first == 0) { res_pair.second = num; } //一番最後に通った素数
		res_pair.first++;
	}
	memo_caves[y][x] = res_pair;

	return res_pair;
}



int main() {
	int N,M;
	//エラトステネスの篩
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 2; i < PRIME_MAX; i++) { is_prime[i] = true; }
	for(int i = 2; i < PRIME_MAX; i++) {
		if (is_prime[i]) {
			for(int j=i+i; j<PRIME_MAX; j+=i) is_prime[j] = false;
		}
	}

	//UPの方向で動く座標..
	MOVE_POINT_OF_ANGLE[UP] = make_pair(0,1);
	MOVE_POINT_OF_ANGLE[LEFT] = make_pair(-1,0);
	MOVE_POINT_OF_ANGLE[BOTTOM] = make_pair(0,-1);
	MOVE_POINT_OF_ANGLE[RIGHT] = make_pair(1,0);

	//UPのときの左の座標..
	LEFT_POINT_OF_ANGLE[UP] = make_pair(-1,0); 
	LEFT_POINT_OF_ANGLE[LEFT] = make_pair(0,-1);
	LEFT_POINT_OF_ANGLE[BOTTOM] = make_pair(1,0);
	LEFT_POINT_OF_ANGLE[RIGHT] = make_pair(0,1);


	while(cin >> M >> N) {
		if (M == 0 && N == 0) break; //Mは数
		fill_n((int *)caves, sizeof(caves)/sizeof(int), 0);
		fill_n((pair<int,int> *)memo_caves, sizeof(memo_caves)/sizeof(pair<int,int>), make_pair(-1,-1));

		vector<pair<int,int> > points(M+1,make_pair(0,0)); //番号に対応する座標たち
		int now_x = CENTER; int now_y = CENTER;
		int now_angle = BOTTOM;

		for(int i=1; i<=M; i++)
		{
			caves[now_y][now_x] = i;
			points[i] = make_pair(now_x,now_y); //番号に対応する座標値

			pair<int,int> left_point = LEFT_POINT_OF_ANGLE[now_angle];
			int left_x = now_x + left_point.first;
			int left_y = now_y + left_point.second;
			if (caves[left_y][left_x] > 0) { //進んでいる方向の左方向がすでにマップされている場合
				//方向はかえない
			}
			else {
				now_angle = (now_angle + 1) % 4; //0,1,2,3
			}

			pair<int,int> move_point = MOVE_POINT_OF_ANGLE[now_angle];
			now_x = now_x + move_point.first;
			now_y = now_y + move_point.second;
		}

		//show();

		pair<int,int> ans_pair = search_to_bottom(points[N].first,points[N].second); //開始する座標
		cout << ans_pair.first << " " << ans_pair.second << endl;
	}

	return EXIT_SUCCESS;
}
