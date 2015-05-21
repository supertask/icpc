#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;
int main() {
	int R,C,K,N,r,c;
	cin >> R >> C >> K >> N;
	vector<pair<int,int> > ames;

	for(int i=0; i<N; i++) {
		cin >> r >> c;
		ames.push_back(make_pair(r,c));
	}

	assert(R <= 50);
	assert(C <= 50);

	int ans = 0;
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			int cell_ame = 0;
			for(int i=0; i<ames.size(); i++) {
				//first=R, second=C
				if (y == ames[i].first || x == ames[i].second) { cell_ame++; }
			}
			//cout << cell_ame << " ";

			if (K == cell_ame) {
				ans++;			
			}
		}
		//cout << endl;
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}
