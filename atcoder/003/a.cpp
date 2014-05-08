#include<iostream>
#include<map>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;

int main() {
	int n;
	string a_str;
	map<char,double> gpa;
	double answer = 0;

	gpa['A'] = 4;
	gpa['B'] = 3;
	gpa['C'] = 2;
	gpa['D'] = 1;
	gpa['F'] = 0;
	cin >> n >> a_str;	
	rep(i,n) {
		answer+= gpa[a_str[i]];
	}
	if (answer == 0) { printf("0\n"); }
	else { printf("%.14f\n",answer/n); }
	
	return 0;
}

