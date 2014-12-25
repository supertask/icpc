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

int main() {
	int T,N,M,K;
	string W,x;
	cin >> T;
	rep(t,T) {
		cin >> N >> M;
		//登録フェイズ
		map<string,vector<string> > nodes;
		map<string,int> node_names;

		rep(n,N) { 
			cin >> W >> K;
			node_names[W] = n;
			rep(k,K) {
				cin >> x;
				nodes[W].push_back(x);
			}
		}

		//編集フェイズ
		vector<vector<long> > graph(N,vector<long>(N,INT_MAX));
		map<string,vector<string> >::const_iterator it = nodes.begin();
		while(it != nodes.end()) {
			int i = node_names[it->first];
			vector<string> children = it->second;
			rep(cc,children.size()) {
				int j = node_names[children[cc]];
				graph[i][j] = 1; //距離1 ページリンクなので必要条件となる（必要十分でない！）
				//graph[j][i] = 1; //距離1
			}
			it++;
		}
		
		/*
		//デバッグ
		rep(i,N) {
			rep(j,N) {
				cout << graph[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;
		*/

		rep(i,N) {
			rep(j,N) {
				rep(k,N) {
					graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
				}
			}
		}

		/*
		//デバッグ
		rep(i,N) {
			rep(j,N) {
				cout << graph[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;
		*/


		//出力フェイズ
		string startman,goalman;
		rep(m,M) {
			cin >> startman >> goalman;
			int s = node_names[startman];
			int g = node_names[goalman];
			if (graph[s][g] == INT_MAX) {
				cout << "NULL" << endl;
			}
			else {
				cout << graph[s][g] << endl;
			}
		}

	}

	return 0;
}
