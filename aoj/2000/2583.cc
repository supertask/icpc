#include<bits/stdc++.h>
#define dump(a) cout << #a << "=" << a << endl
using namespace std;

#define TREE_LEN 1001
#define STR_LEN 5000 //50+1000

char tree_str[TREE_LEN][STR_LEN];
int N;
string line;

void replace_before() {
	for(int y=0; y<N; y++) { //1~1000
		if (tree_str[y][0] != '.') { continue; } //英単語あれば

		for(int x=0; x<STR_LEN; x++)
		{
			if (tree_str[y][x] != '.') { //単語があれば
				if ((x-1) >= 0) {
					tree_str[y][x-1] = '+';
					break;
				}
			}
		}
	}
}

void replace_tate()
{
	for(int x=0; x<STR_LEN; x++) {
		bool is_start = false;
		//開始点,終了点のリスト
		vector<pair<int,int> > ys;
		vector<int> tmp_pair;

		for(int y=0; y<N; y++) { //1~1000
			if ('a' <= tree_str[y][x] && tree_str[y][x] <= 'z') {
				tmp_pair.clear();
			}
			else if (tree_str[y][x] == '+') {
				if (tmp_pair.size() == 0) {
					tmp_pair.push_back(y+1);
				}
				else if (tmp_pair.size() == 1) {
					tmp_pair.push_back(y-1);
					ys.push_back(make_pair(tmp_pair[0],tmp_pair[1]));
					tmp_pair.clear(); //空っぽに
					tmp_pair.push_back(y+1);
				}
			}
		}

		for(int i=0; i<ys.size(); i++) {
			for (int y=ys[i].first; y<=ys[i].second; y++) {
				if (tree_str[y][x] == '.') { tree_str[y][x]='|'; }
			}
		}
	}
}

void replace_other() {
	for(int y=0; y<N; y++) { //1~1000
		for(int x=0; x<STR_LEN; x++) {
			if (tree_str[y][x]=='.') {
				tree_str[y][x] = ' ';
			}
		}
	}
}


void show() {
	for(int y=0; y<N; y++) { //1~1000
		for(int x=0; x<STR_LEN; x++)
		{
			if (tree_str[y][x] == '0') {
				break;
			}
			else {
				cout << tree_str[y][x];
			}
		}
		cout << endl;
	}
}

int main() {
	while(cin >> N) {
		if (N == 0) { break; }

		for(int y=0; y<N; y++) { //1~1000
			for(int x=0; x<STR_LEN; x++) {
				tree_str[y][x] = '0';
			}
		}

		for(int y=0; y<N; y++) { //1~1000
			cin >> line;

			for(int x=0; x<line.size(); x++) {
				tree_str[y][x] = line[x];
			}
		}
		replace_before();
		replace_tate();
		replace_other();
		show();
	}

	return EXIT_SUCCESS;
}
