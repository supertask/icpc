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
#include<cctype> //isdigit

#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;

int expr(string& s, int& i);
int term(string& s, int& i);
int factor(string& s, int& i);
int number(string& s, int& i);

int expr(string& s, int& i)
{
	int value = term(s,i); //必ずexprが出て来たとき，termが出てくる
	while(s[i] == '+' || s[i] == '-')
	{
		char ope = s[i];
		i++;
		if (ope == '+') value += term(s,i);
		else value -= term(s,i);
	}
	return value;
}

int term(string& s, int& i)
{
	int value = factor(s,i);
	while(s[i] == '*' || s[i] == '/')
	{
		char ope = s[i];
		i++;
		if (ope == '*') value *= factor(s,i);
		else value /= factor(s,i);
	}
	return value;
}

int factor(string& s, int& i)
{
	if(isdigit(s[i])) return number(s,i); //numberなら即刻return．そのため，exprが必ず次に来る．
	i++;
	int value = expr(s,i);
	i++;
	return value;
}

int number(string& s, int& i)
{
	int n = s[i] - '0';
	i++;
	while(isdigit(s[i])) { n = n * 10 + s[i] - '0'; i++; }
	return n;
}

int main()
{
	string str = "1+2*6/(10-7)";
	int i = 0;
	cout << str << " = " << expr(str, i) << endl; // => 5

	return 0;
}
