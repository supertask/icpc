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

using namespace std;

struct Node {
	vector<int> edges_to;
	vector<int> edges_cost;
	vector<int> edges_hour;
	vector<int> edges_company;
	bool is_check;
	int cost;
	int hour;
};

vector<int> passports;

int main() {
	int N,M,H,K;
	int a,b,c,h,r;
	int S,T,P;
	int l,d,k;

	while(cin >> N >> M >> H >> K) 
	{
		if (N==0&&M==0&&H==0&&K==0) break;
		Node nodes[N+1]; //1 origin

		rep(ni,N+1) {
			nodes[ni].is_check = false;
			nodes[ni].cost = INT_MAX;
			nodes[ni].hour = INT_MAX;
			nodes[ni].company = INT_MAX;
		}
		rep(mi,M) {
			cin >> a >> b >> c >> h >> r;
			nodes[a].edges_to.push_back(b);
			nodes[b].edges_to.push_back(a);
			nodes[a].edges_cost.push_back(c);
			nodes[b].edges_cost.push_back(c);
			nodes[a].edges_hour.push_back(h);
			nodes[b].edges_hour.push_back(h);
			nodes[a].edges_company.push_back(r);
			nodes[b].edges_company.push_back(r);
		}
		cin >> S >> T;
		nodes[S].cost=0;
		nodes[S].hour=0;
		nodes[S].is_check=false;

		cin >> P; 
		//0のとき，通常料金，パスのあるときはすべて無料
		rep(pi,P) {
			cin >> l >> d; //d=パスポート料金
			rep(li,l) { //パスポートの会社の番号たち
				cin >> k;
				passports.push_back(k);
			}
		}

		//ダイクストラ法
		while(true) {
			Node doneNode = NULL; //確定ノード
			rep(i,N+1) {
				if (nodes[i].is_check || nodes[i].cost < 0) {
					continue;
				}
				else if (doneNode == NULL || node.cost < doneNode.cost) {
					doneNode = nodes[i];
				}
			}
			if (doneNode == NULL) { break; }
			doneNode.is_check = true;
			// 接続先ノードの情報を更新する
			for i = [0, doneNode.edges_to.size()-1]:
				to = doneNode.edges_to[i]
				cost = doneNode.cost + doneNode.edges_cost[i]
				if nodes[to].cost < 0 || cost < nodes[to].cost:
					nodes[to].cost = cost
		}

	}

	return 0;
}
