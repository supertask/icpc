#include<iostream>
using namespace std;

int main() {
	int N,p,ans=0;
	cin >> N;
	for(int i=0; i < N; i++) {
		cin >> p;
		if (p < 80) {
			ans+=(80-p);
		}
	}
	cout << ans << endl;

	return 0;
}
