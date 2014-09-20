/* AC */
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

int main()
{
	int N,a,b;
	int nums[1000001];
	vector<int> lefts;
	vector<int> rights;

	cin >> N;
	rep(i,1000001)
	{
		nums[i] = 0;
	}
	rep(i,N)
	{
		cin >> a >> b;
		nums[a]++;
		nums[b+1]--;
		lefts.push_back(a);
		rights.push_back(b);
	}

	int maxi = nums[0];
	int index = 0;
	REP(i,1,1000001)
	{
		nums[i] += nums[i-1];
		if (nums[i] > maxi) {
			maxi = nums[i];
			index = i;
		}
	}

	int cnt=0;
	rep(i,lefts.size()) //0 <= N <= 100000
	{
		if (lefts[i] <= index && index <= rights[i]) cnt++;
	}
	cout << cnt << endl;
	

	return 0;
}
