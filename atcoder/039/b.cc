#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;

int kaijo(int up, int bottom1, int bottom2) {
	int max1 = max(bottom1,bottom2);
	int min1 = min(bottom1,bottom2);
	vector<int> ups;
	for (int i=up-max1+1; i <= up; i++) {
		ups.push_back(i);
	}

	vector<int> bottoms;
	for (int i=1; i<=min1; i++) {
		bottoms.push_back(i);
	}

	for (int i=0; i<ups.size(); i++) {
		for (int j=0; j<bottoms.size(); j++) {
			if (ups[i] % bottoms[j] == 0) {
				ups[i]
			}
		}
	}

	return res;
}

int main() {
	int N,K;
	int students[100+1];
	cin >> N >> K;

	int multi = K / N;
	int mod = K % N;

	for(int i=0; i < N; i++) { //全員に分配
		students[i] = multi;
	}
	for(int i=0; i < mod; i++) { //残り物も分配
		students[i]++;
	}

	bool is_zero=false;
	for(int i=0; i < N; i++) {
		if (students[i] == 0) {
			is_zero=true;
			break;
		}
	}

	dump(mod);
	dump(N-mod);
	long long ans=0;
	ans = kaijo(N,mod,N-mod);
	cout << ans << endl;
	


	return EXIT_SUCCESS;
}
