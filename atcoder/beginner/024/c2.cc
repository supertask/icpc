#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;

int main() {
	int R,C,K,N,r,c;
	cin >> R >> C >> K >> N;
	vector<pair<int,int> > ames;

	vector<int> r_ame_cnt(R+1,0);
	vector<int> c_ame_cnt(C+1,0);
	for(int i=0; i<N; i++) {
		cin >> r >> c;
		ames.push_back(make_pair(r,c));
		r_ame_cnt[r]++;
		c_ame_cnt[c]++;
	}

	vector<int> c_table(C+1,0);
	for(int x=1; x<=C; x++) {
		c_table[c_ame_cnt[x]]++;
	}

	int ans = 0;
	for(int y=1; y<=R; y++) { //Yはすべてたどる
		int c_ame_cnt = K - r_ame_cnt[y];
		ans += c_table[c_ame_cnt]; //出現回数
	}
	cout << ans << endl;


	return EXIT_SUCCESS;
}
