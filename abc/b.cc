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
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()


int main() {
	std::string s;
	std::cin >> s;
	std::transform(s.cbegin(), s.cend(), s.begin(), tolower);
	s[0] = s[0] - ('a' - 'A');
	std::cout << s << std::endl;

	return 0;
}
