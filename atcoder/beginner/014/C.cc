/* WA */
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

struct Range {
	int left;
	int right;
	int value; //count
	bool operator<( const Range& r ) const {
		return value > r.value;
	}
};

int main() {
	int N,a,b;
	vector<Range> ranges;

	cin >> N;

	rep(i,N) { //MAX 10^5
		cin >> a >> b;
		Range range;
		range.left = a;
		range.right = b;
		range.value = 1;
		ranges.push_back(range);
	}

	rep(i,ranges.size())
	{
		rep(j,ranges.size())
		{
			if ((ranges[i].left <= ranges[j].left && ranges[j].left <= ranges[i].right) ||
				(ranges[i].left <= ranges[j].right && ranges[j].right <= ranges[i].right) )
			{
				ranges[i].value++;
				ranges[j].value++;
			}
		}
	}

	sort(ALL(ranges));
	int max_value = ranges[0].value;

	int cnt=0;
	rep(i,ranges.size())
	{
		if (ranges[i].value == max_value) cnt++;
	}
	cout << cnt << endl;

	return 0;
}
