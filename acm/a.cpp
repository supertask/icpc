#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#include<ctime>
#include<cstring>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_    str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
using namespace std;

typedef struct data {
	int high;
	int width;
	double daiagonal;
	bool operator<(const data& right) const {
		if (daiagonal == right.daiagonal) {
			return high < right.high;
		}
		else {
			return daiagonal < right.daiagonal;
		}
	}
} Data;

vector<Data> datas;
vector<int> pows;
vector<int> bufs;

void all_permutation(int i, const int size) {
	if (i == size) {
		Data a_data;
		if (bufs[0] < bufs[1]) {
			a_data.high = bufs[0];
			a_data.width = bufs[1];
			a_data.daiagonal = pow(bufs[0],2) + pow(bufs[1],2);
			datas.push_back(a_data);
		}
	}
	else {
		rep(j,pows.size()) {
			bufs[i] = pows[j];
			all_permutation(i+1,size);
		}
	}
	return;
}

int main() {
	int H,W;
	vector<int> hs,ws;

	rep(i,142) {
		pows.push_back(i+1);	
	}
	bufs.resize(2);
	all_permutation(0,2);
	sort(all(datas));

	while (cin >> H >> W) {
		if (H == 0 && W == 0) { break; }
		int daiagonal = pow(H,2) + pow(W,2);
		rep(i,datas.size()) {
			if (daiagonal <= datas[i].daiagonal && datas[i].high == H && datas[i].width == W)
			{
				cout << datas[i+1].high << " " << datas[i+1].width << endl;
				break;
			}
		}
	}

	return 0;
}
