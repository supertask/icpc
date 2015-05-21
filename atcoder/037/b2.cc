#include<bits/stdc++.h>
using namespace std;

int M,N,u,v;
bool is_tree;
vector<vector<int> > nodes;
vector<bool> is_visit;

void dfs(int current_v, int previous_v) {
	if (is_visit[current_v]) { 
		is_tree=false;
		return;
	}
	is_visit[current_v] = true;
	//cout << current_v << endl;

	for(int i=0; i<nodes[current_v].size(); i++) {
		if (nodes[current_v][i] != previous_v) {
			dfs(nodes[current_v][i], current_v);
		}
	}
	return;
}

int main() {

	cin >> N >> M;
	nodes.resize(N);
	is_visit.resize(N,0);

	for(int i=0; i<M; i++) {
		cin >> u >> v; --u; --v;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}
	
	int ans=0;
	for(int i=0; i<N; i++) {
		if (!is_visit[i]) {
			is_tree = true;
			dfs(i,-1);
			ans+=is_tree;
		}
	}
	cout << ans << endl;


	return EXIT_SUCCESS;
}
