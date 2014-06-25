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
#define MAX 30000 // finalにすると一度セットした値が変更できなくなる．

using namespace std;
template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, T b) { if(b < a) a = b; }

int main() 
{
		bool prime[MAX];

		for (int i=2; i<MAX; i++) prime[i] = true;
		for (int i=2; i<MAX; i++) 
		{
				if (prime[i]) { 
						cout << i << endl; 
						for (int j=i+i; j<MAX; j+=i) prime[j] = false; 
				}
		}

		return 0;
}
