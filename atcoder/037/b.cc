#include<iostream>
#include<vector>
using namespace std;

int N,M,u,v;
int ans=0;
bool is_heiro=false;
vector<vector<int> > nodes(101);
vector<bool> visited(101,false);
vector<int> visited_node_nums;

void dfs(int ni) {
	//if (visited[ni]) { return; }
	visited[ni]=true; //探索されていないグラフのみ探すため
	for(int i=0; i<visited_node_nums.size(); i++) {
		if (visited_node_nums[i] == ni) { 
			cout << "double: " << ni << endl;
			is_heiro=true;
			return;
		} //閉路になる
	}
	cout << "ni=" << ni << endl;

	for(int i=0; i<nodes[ni].size(); i++) {
		visited_node_nums.push_back(ni);
		if (!visited[]) {
			dfs(nodes[ni][i]);
		}
	}
}

int main() {

	cin >> N >> M;
	for(int i=0; i<M; i++) {
		cin >> u >> v;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}

	for(int ni=1; ni<=N; ni++) { //1<=i<=N
		cout << "ni=" << ni << ": " << nodes[ni].size() << endl;
		if (visited[ni]) { continue; }
		else if (nodes[ni].size() == 0) {
			ans++;
			//cout << "空" << endl;
		}
		else {
			is_heiro=false;
			visited_node_nums.clear();
			dfs(ni);
			if (!is_heiro) { ans++; }
		}
	}
	cout << ans << endl;

	return 0;
}
