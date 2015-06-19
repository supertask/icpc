#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;

int main() {
	string A,B;
	cin >> A >> B;

	//cout << A << B << endl;
	int ans = INT_MIN;
	for(int i=0; i<6; i++) { //0~5
		for(int num=0; num<=9; num++) {
			if ((num==0&&i==0) || (num==0&&i==3)) { continue; }
			string AA = A;
			string BB = B;
			if (0 <= i && i < 3) {
				AA[i] = (char)(num+'0');
			}
			else if (3 <= i && i < 6) {
				BB[i-3] = (char)(num+'0');
			}

			int iA = stoi(AA);
			int iB = stoi(BB);
			ans = max(iA-iB,ans);
		}
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}
