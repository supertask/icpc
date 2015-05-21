#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	int u,v,l;
	int ans=0;
	int in_gragh[301][301];
	int gragh[301][301][301];
	fill_n((int *)in_gragh, (in_gragh + sizeof(in_graph)/sizeof(int)), -1e14);
	fill_n((int *)gragh, (gragh + sizeof(graph)/sizeof(int)), -1e14);

	cin >> N >> M;
	vector<int> starts;
	vector<pair<int> > inputs;
	for(int i=0; i<M; i++) {
		cin >> u >> v >> l;
		in_gragh[u][v] = l;
		inputs.push_back(make_pair(u,v));
		if (u == 1) { starts.push_back(v); }
		else if (v == 1) { starts.push_back(u); }
	}

	/*
	bool is_visit[301];
	for(int i=0; i<M; i++) {
		Pair<int> aPair = inputs[i];
		if (aPair.first == 1 || aPair.second == 1) {
			graph[i][aPair.first][aPair.second] = graph[u][v];
			is_visit[i] = true;
		}
		else {
			graph[i][aPair.first][aPair.second] = graph[u][v];
		}
	}
	*/

	for(int i=0; i<N; i++) {
		for(int k=0; k<N; k++) { //間
			for(int j=0; j<N; j++) {
				gragh[i][j] = min(gragh[i][j],gragh[i][k]+gragh[k][j]);
			}
		}
	}
	for(int i=0; i<=N; i++) { //間
		for(int j=0; j<=N; j++) {
			cout << gragh[i][j] << " ";
		}
		cout << endl;
	}

	int mini=INT_MAX;
	for(int i=0; i<=starts.size(); i++) {
		mini=min(gragh[starts[i]][1],mini);
	}
	cout << mini << endl;
	
	return EXIT_SUCCESS;
}
