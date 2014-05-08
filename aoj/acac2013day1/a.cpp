/* AC */
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
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
using namespace std;

vector<string> split(string a_str, const char *re) {
	vector<string> strs;
	rep_split(tok,a_str,re) {
		strs.push_back(string(tok));
	}
	return strs;
}

int main() {
	int N,T;
	string a_str;
	vector<string> strs;
	vector<string> res;
	string back_strs[3];
	bool is_first = true;

	cin >> N >> T; cin.ignore();

	rep(i,N) {	
		vector<string> strs;
		getline(cin,a_str);
		strs = split(a_str,": ");
		if (is_first) {
			is_first = false;
		}
		else {
			time_t ti;
			struct tm t_back = *localtime(&ti);
			struct tm t = *localtime(&ti);
			t_back.tm_hour = atoi(back_strs[0].c_str());
			t_back.tm_min = atoi(back_strs[1].c_str());
			t.tm_hour = atoi(strs[0].c_str());
			t.tm_min = atoi(strs[1].c_str());
			int diff = difftime(mktime(&t),mktime(&t_back))/60;
			if (diff >= T) {
				res.push_back(back_strs[2] + " " + to_string(diff));
			}
		}
		back_strs[0] = strs[3];
		back_strs[1] = strs[4];
		back_strs[2] = strs[5];
	}
	cout << res.size() << endl;
	rep(i,res.size()) {
		cout << res[i] << endl;
	}

	return 0;
}
