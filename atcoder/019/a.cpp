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

int main() {
	string a_str;
	cin >> a_str;
	rep(i,a_str.size()) {
		if (a_str[i] == 'O') {
			cout << '0';
		}
		else if (a_str[i] == 'D') {
			cout << '0';
		}
		else if (a_str[i] == 'I') {
			cout << '1';
		}
		else if (a_str[i] == 'Z') {
			cout << '2';
		}
		else if (a_str[i] == 'S') {
			cout << '5';
		}
		else if (a_str[i] == 'B') {
			cout << '8';
		}
		else {
			cout << a_str[i];
		}
	}
	cout << endl;

	return 0;
}
