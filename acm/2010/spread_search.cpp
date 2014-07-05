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
	double taikaku;
	bool operator<(const data& right) const {
		return (taikaku < right.taikaku) && (high < right.high);
	}
} Data;

vector<Data> datas;

/*
int bsearch(int taikaku) {
	int first = 0;
	int last = datas.size();
	int middle;
	while (first+1 < last) {
		middle = (first+last)/2;
		if (taikaku < datas[middle].taikaku) {
			last = middle;
		}
		else {
			first = middle;
		}
	}
	if (first < last && datas[first].taikaku == taikaku) {
		return first;
	}
	else {
		return -1;
	}
}
*/

Data *spread_search(int high, int width, int i, bool is_left) {
	int taikaku = datas[i].taikaku;
	while (true) {
		if (i < 0 || datas.size() < i) { break; }
		if (taikaku != datas[i].taikaku) { break; }		
		if (datas[i].high == high && datas[i].width == width) {
			if (datas.size() < i+1) { break; }
			return &datas[i+1];
		}
		if (is_left) { i--; }
		else { i++; }
	}
	return NULL;
}

int main() {
	int H,W;
	vector<int> hs,ws;

	while (cin >> H >> W) {
		if (H == 0 && W == 0) { break; }
		Data a_data;
		a_data.high = H;
		a_data.width = W;
		a_data.taikaku = pow(H,2) + pow(W,2);
		cout << H << " " << W << ": ";
		cout << a_data.taikaku << endl;
		datas.push_back(a_data);
		hs.push_back(H);
		ws.push_back(W);
	}
	cout << endl;
	sort(all(datas));
	rep(i,datas.size()) {
		int taikaku = pow(hs[i],2) + pow(ws[i],2);
		int index = bsearch(taikaku);

		Data *data_1 = spread_check(hs[i],ws[i],index,true);
		Data *data_2 = spread_check(hs[i],ws[i],index,false); 
		if (data_1 != NULL) {
			cout << data_1->high << " " << data_1->width << endl;
		}
		else if (data_2 != NULL) {
			cout << data_2->high << " " << data_2->width << endl;
		}
	}

	return 0;
}
