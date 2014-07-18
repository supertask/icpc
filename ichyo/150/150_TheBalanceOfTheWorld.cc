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
#include<string>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
// #define dump(a) cerr << #a << "=" << (a) << endl

using namespace std;

int main() {
	string line;
	char left_paren;
	bool is_yes;
	vector<char> left_parens;

	while(getline(cin,line)) {
		if (line[0] == '.') break;

		left_parens.clear();
		is_yes = true;

		rep(i,line.size()) {
			if (line[i] == '(') {
				left_parens.push_back(line[i]);
			}
			else if (line[i] == '[') {
				left_parens.push_back(line[i]);
			}
			else if (line[i] == ')') {
				if (left_parens.empty()) {
					is_yes = false;
				}
				else {	
					left_paren = left_parens.back();
					if (left_paren != '(') {
						is_yes = false;
					}
					left_parens.pop_back();
				}
			}
			else if (line[i] == ']') {
				if (left_parens.empty()) {
					is_yes = false;
				}
				else {	
					left_paren = left_parens.back();
					if (left_paren != '[') {
						is_yes = false;
					}
					left_parens.pop_back();
				}
			}
		}
		if (left_parens.size() > 0)
			is_yes = false;

		if (is_yes) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	

	return 0;
}
