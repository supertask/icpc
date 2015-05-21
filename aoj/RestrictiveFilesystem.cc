#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;



struct Point {
	int first;
	int len;
	int sikibetu_id;
};
vector<Point> sys;

int read_sys(int real_i) {
	rep(i,sys.size()) {
		int first = sys[i].first;
		int last = first + sys[i].len;
		/*
		dump(first);
		dump(last);
		dump(real_i);
		*/
		if (first <= real_i && real_i < last) {
			return sys[i].sikibetu_id;		
		}
	}
	return -1;
}

void delete_sys(int siki) {
	rep(i,sys.size()) {
		if (sys[i].sikibetu_id == siki) {
			sys.erase(sys.begin() + i); //iの要素を削除
			i--;
		}
	}
}

void write_sys(int siki, int len) {
	int tune_index = 0;

	rep(i,sys.size()) {
		if (tune_index != sys[i].first) {
			//tune_index <= hoge <= sys[i].firstの間が空っぽ
			int between = (sys[i].first - tune_index);

			if (len == 0) { //Here
			}
			else if (between > len) {
				Point p;
				p.first=tune_index;
				p.len=len;
				p.sikibetu_id = siki;
				sys.insert(sys.begin()+i, p);
				len=0; //0
				dump(tune_index); //421165 
				dump(between); //7725519
				dump(i); //13090
				dump(sys[i].len); //0
				dump(sys.size()); //0
			}
			else {
				Point p;
				p.first=tune_index;
				p.len=between;
				p.sikibetu_id = siki;
				sys.insert(sys.begin()+i, p);
				len-=between;
			}
		}
		tune_index += sys[i].len;
	}

	if (len > 0) {
		Point p;
		p.first=tune_index;
		p.len=len;
		p.sikibetu_id=siki;
		sys.push_back(p);
	}

}

void show() {
	dump("-------");
	rep(i,sys.size()) {
		dump(sys[i].first);
		dump(sys[i].len);
		dump(sys[i].sikibetu_id);
	}
}

int main() {
	int N;
	char command;
	int arg1,arg2;

	while(cin >> N) {
		if (N == 0) { break; }
		sys.clear();
		rep(i,N) {
			cin >> command;

			if (command == 'R') {
				cin >> arg1;
				cout << read_sys(arg1) << endl;
			}
			else if (command == 'D') {
				cin >> arg1;
				delete_sys(arg1);
			}
			else if (command == 'W') {
				cin >> arg1 >> arg2;
				cout << command << " " << arg1 << " " << arg2 << endl;
				write_sys(arg1,arg2);
			}
			show();
		}
		cout << endl;
	}

	return 0;
}
