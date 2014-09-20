/* TLE */
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


struct Node {
	bool is_visit;
	vector<int> nodes;
};

vector<Node> graph;

int search(int now, const int end, int depth)
{
	depth++;
	if (graph[now].is_visit) 
		return 0;
	if (now == end) 
		return depth;
	graph[now].is_visit = true;

	rep(i,graph[now].nodes.size())
	{
		int num = search(graph[now].nodes[i], end, depth);
		if (num > 0) return num;
	}
	return 0;
}

int main() {
	int N,Q,a,b;

	cin >> N;
	graph.resize(N+1);

	rep(i,N-1) {
		cin >> a >> b;
		graph[a].nodes.push_back(b);
		graph[b].nodes.push_back(a);
	}

	cin >> Q;

	rep(i,Q) {
		cin >> a >> b;
		cout << search(a,b,0) << endl;
		rep(i,graph.size()) { graph[i].is_visit = false; }
	}

	return 0;
}
