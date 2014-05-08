#include <iostream>
#include <cmath>
using namespace std;
int F[1001];
int P[10010];

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
	int V,D;
	int count;
	
	F[0] = 1, F[1] = 2;
	for (int i=0; i<1001; i++) {
		F[i+2] = (F[i] + F[i+1]) % 1001;
	}
	
	while(cin >> V >> D) {
		count = 0;
		init(V+1); //自分を設定
		for(int i=1; i<=V; ++i) {
			for(int j=i+1; j<=V; ++j) {
				if (abs(F[j] - F[i]) < D) {
					unite(i,j);
				}
			}
		}
		for(int i=1; i<=V; ++i) {
			if (root(i) == i) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
