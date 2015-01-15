/*
 * <formula> ::= 0 | 1 | 2 | P | Q | R |
 *    -<formula> | (<formula>*<formula>) | (<formula>+<formula>)
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

int table_seki[3][3];
int table_wa[3][3];
int P,Q,R;

int formula(string& s, int& i);
int main();

int formula(string& s, int& i)
{
	int left=0, right=0;	
	char ope=0;

	switch(s[i])
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case 'P': return P;
		case 'Q': return Q;
		case 'R': return R;
		case '-':
			i++;
			left = formula(s,i);
			if (left == 0) { return 2; }
			else if (left == 2) { return 0; }
			else { return 1; }
		case '(':
			i++;
			left = formula(s,i);
			i++;
			ope = s[i];
			i++;
			right = formula(s,i);
			i++; //)
			if (ope == '*') {
				return table_seki[left][right];
			}
			else {
				return table_wa[left][right];
			}
		defalt:
			return 0; //起こることは本来ない．扱う字句または構文のミス
	}
	return 0; //起こることはないはず
}

int main() {
	//積集合
	table_seki[0][0] = 0; //y,x
	table_seki[1][0] = 0; //y,x
	table_seki[2][0] = 0; //y,x
	table_seki[0][1] = 0; //y,x
	table_seki[1][1] = 1; //y,x
	table_seki[2][1] = 1; //y,x
	table_seki[0][2] = 0; //y,x
	table_seki[1][2] = 1; //y,x
	table_seki[2][2] = 2; //y,x

	//和集合
	table_wa[0][0] = 0; //y,x
	table_wa[1][0] = 1; //y,x
	table_wa[2][0] = 2; //y,x
	table_wa[0][1] = 1; //y,x
	table_wa[1][1] = 1; //y,x
	table_wa[2][1] = 2; //y,x
	table_wa[0][2] = 2; //y,x
	table_wa[1][2] = 2; //y,x
	table_wa[2][2] = 2; //y,x

	string line;
	vector<int> binary;
	binary.push_back(0);
	binary.push_back(1);
	binary.push_back(2);
	int pattern_cnt = 0;

	while(true) {
		cin >> line;
		pattern_cnt = 0;
		if (line[0] == '.') { break; }

		rep(p,3) {
			rep(q,3) {
				rep(r,3) {
					P=p; Q=q; R=r;
					int i = 0;
					int result = formula(line,i);

					if (result == 2) { pattern_cnt++; }
				}
			}
		}
		cout << pattern_cnt << endl;
	}

	return 0;
}
