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

bool is_kaimon(string a_str) {
	int end = a_str.size()-1;
	rep(i,a_str.size()) {
		if (a_str[i] != a_str[end-i]) {
			return false;
		}
	}
	return true;	
}

int main() {
	string a_str;
	int count=0;

	cin >> a_str;
	do {
		if (! is_kaimon(a_str)) { count++; }
	} while(next_permutation(a_str.begin(),a_str.end()));
	cout << count << endl;

	return 0;
}
