#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int P[10010];
int N, M, A[10010], B[10010], COST[10010];
pair<int,int> bridge[10010];

void init(int N) {
	for (int i=0; i<N; ++i) { P[i] = i; }
}

int root(int a) {
	if (P[a] == a) return a;
	return (P[a] = root(P[a]));
}

bool is_same_set(int a, int b) {
	return root(a) == root(b);
}

void unite(int a, int b) {
	P[root(a)] = root(b);
}

int main() {
	while(cin >> N >> M) {
		int costs=0;
		if (N == 0 && M == 0) { break; }
		init(N);
		
		for (int i=0; i<M; i++) {
			cin >> A[i] >> B[i] >> COST[i];
			bridge[i].first = COST[i];
			bridge[i].second = i;
		}
		sort(bridge,bridge+M);
		
		for (int i=0; i<M; i++) {
			int cost = bridge[i].first;
			int machiA = A[bridge[i].second];
			int machiB = B[bridge[i].second];
			if (!is_same_set(machiA, machiB))
			{
				unite(machiA, machiB);
				costs+=cost;
			}
		}
		cout << costs << endl;
	}
	return 0;
}
