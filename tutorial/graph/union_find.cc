/*
 * UnionFindTree
 * 1.各木（ID=ルート）のエッジの数（閉路も含まれる）をカウントする
 * 2.木のサイズ(ノード数)をUnionFindで調べる.木であるときのエッジ数（ノード数-1）をカウントする
 * 1,2の結果からエッジ数が一致した場合はアンスカウントし，そうでない（閉路）の場合はアンスカウントしない.
*/
#include<iostream>
#include<vector>
using namespace std;

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};


int main() {
	int N,M,u,v;
	cin >> N >> M;
	vector<pair<int,int> > edges;
	UnionFind uf;
	uf.init(N);

	for(int i=0; i<M; i++) {
		cin >> u >> v; --u; --v;
		uf.unionSet(u,v);
		edges.push_back(make_pair(u,v));
	}

	vector<int> graph_sizes(N,0);
	for(int i=0; i<edges.size(); i++) {
		graph_sizes[uf.root(edges[i].first)]++;
	}

	int ans=0;
	for(int i=0; i<N; i++) {
		if(uf.root(i) == i) {
			ans += (graph_sizes[i] == (uf.size(i) - 1)); //エッジの数を比較
		}
	}
	cout << ans << endl;

	return 0;
}
