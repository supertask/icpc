#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()

using namespace std;

int main() {
	int n;

	cin >> n;
	vector<string> words(n);

	rep(i,n) {
		cin >> words[i];		
		reverse(all(words[i]));
	}
	sort(all(words));
	rep(i,n) {
		reverse(all(words[i]));
		cout << words[i] << endl;
	}

	return 0;
}

