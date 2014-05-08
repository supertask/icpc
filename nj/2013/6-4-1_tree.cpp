#include <iostream>
#include <vector>
using namespace std;

int N;
int P[10010];
vector<int> memo;
int ans;

void searchFirst(int now) {
	memo.push_back(now);
    /*
    printf("先祖リスト: ");
    for (int i=0; i<memo.size(); i++) {
        printf("%d ", memo[i]);
    }
    printf("\n");
     */
    if (P[now] == -1) { return; }
	searchFirst(P[now]);
}

void searchSecond(int now) {
//    printf("%d ", now);
    for (int i=0; i<memo.size(); i++) {
		if (now == memo[i]) {
			ans = memo[i];
			return;
		}
	}
	if (P[now] == -1) { return; }
	searchSecond(P[now]);
}

int main() {
	int T;
	scanf("%d",&T);
	for (int t=0; t<T; ++t) {
		scanf("%d",&N);
		fill(P, P+10010, -1);
		for (int i=1; i<N; ++i) {
			int p, c;
			scanf("%d %d", &p, &c);
			P[c] = p;
		}
		
		int A,B;
		scanf("%d %d", &A, &B);
		searchFirst(A);
		searchSecond(B);
//        printf("\n");
		printf("%d\n", ans);

		memo.clear();
	}
	return 0;
}