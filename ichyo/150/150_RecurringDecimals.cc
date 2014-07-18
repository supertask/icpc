/*
 * 
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1180&lang=jp
 */
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

int main() {
	int num,L;
	stringstream ss;

	while(cin >> num >> L) {
		if(num==0 && L==0) break; 

		ss << num;
		string num_str = ss.str();
		if (num_str.size() != L) {
			int diff_L = L - num_str.size();
			string diff_zero(diff_L,'0');
			num_str = diff_zero + num_str;
		}
		
		int max_num=0;
		int min_num=INT_MAX;
		int num_tmp=0;
		cout << num_str << endl;
		sort(ALL(num_str));
		
		do {
			num_tmp = stoi(num_str);
			//dump(num_str);
			chmax(max_num,num_tmp);
			chmin(min_num,num_tmp);
		} while(next_permutation(ALL(num_str)) );
		dump(max_num);
		dump(min_num);

		ss.str("");
		ss.clear();
	}

	return 0;
}
