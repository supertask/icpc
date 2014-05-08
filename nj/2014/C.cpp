#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

typedef struct dict {
	string str;
	int num;
	bool operator<( const dict& right ) const { 
		if (str == right.str) {
			return num < right.num; 
		}
		else {
			return str < right.str; 
		}
	} 
} Dict;

int main() {
	// unique_copy
	vector<Dict> dicts;
	string a_str;
	int num;
	int count = 0;
	while(cin >> a_str >> num) {
		Dict a_dict;
		a_dict.str = a_str;
		a_dict.num = num;
		dicts.push_back(a_dict);
		count++;
	}
	sort(all(dicts));

	string back_st = "";
	vector<int> tmp_nums;
	bool is_first = true;
	rep(i,count) 
	{
		if (!is_first) { 
			if (back_st == dicts[i].str) {
				tmp_nums.push_back(dicts[i].num);
			}
			else {
				tmp_nums.push_back(dicts[i].num);
				cout << dicts[i].str << endl;
				rep(j,tmp_nums.size()) {
					cout << tmp_nums[j];
				}
				cout << endl;
				tmp_nums.clear();
			}
		}
		back_st = dicts[i].str;
		is_first = false;
	}

	return 0;
}
