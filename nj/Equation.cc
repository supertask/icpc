/*
 *
 * <equation> ::= <formula> "=" <formula>
 * <formula>  ::= "T" | "F" |
 * "a" | "b" | "c" | "d" | "e" | "f" |
 * "g" | "h" | "i" | "j" | "k" |
 * "-" <formula> |
 * "(" <formula> "*" <formula> ")" |
 * "(" <formula> "+" <formula> ")" |
 * "(" <formula> "->" <formula> ")"
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


vector<bool> var_pattern;
bool equation(string& s, int& i);
bool formula(string& s, int& i);


bool equation(string& s, int& i)
{
	bool left = formula(s,i);
	i++; //=
	i++; //formula
	bool right = formula(s,i);

	//cout << left << "=" << right << endl;

	return left == right;
}


bool formula(string& s, int& i)
{
	bool left=false,right=false;	
	char ope=0;
	bool ans = false;

	switch(s[i])
	{
		case 'T':
			ans = true;
			break;
		case 'F':
			ans = false;
			break;
		case '-':
			i++;
			return !formula(s,i);
		case '(':
			i++;
			left = formula(s,i);
			i++; 
			ope = s[i];
			if (ope == '-') { i++; ope='>'; } //->
			i++;
			right = formula(s,i);

			if (ope == '*') {
				ans = left * right;	
			}
			else if (ope == '+') {
				ans = left + right;	
			}
			else if (ope == '>') {
				ans = (!left) + right;
			}
			i++; //')'
			break;

		default:
			if ('a' <= s[i] && s[i] <= 'k') {
				int var_num = (int)(s[i] - 'a');
				ans = var_pattern[var_num];
			}
			//cout << "index=" << var_num << " var=" << s[i] << endl;
			//cout << s[i] << " = " << var_pattern[var_num] << endl;
			break;
	}

	return ans;
}



int main() {
	string line;
	
	while(cin >> line)
	{
		if (line[0] == '#') break;

		bool is_yes = true;
		rep(j,2048) {
			int i=0;
			int num = j;
			rep(k,11)
			{
				var_pattern.push_back((num & 1));
				//cout << (num & 1) << " ";
				num >>= 1;
			}
			//cout << endl;
			if (!equation(line,i)) { is_yes = false; break; }
			var_pattern.clear();
		}
		cout << (is_yes ? "YES" : "NO") << endl;
		//cout << "-----------" << endl;
	}

	return 0;
}
