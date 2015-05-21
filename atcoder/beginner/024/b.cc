#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;
int main() {
	int N;
	string S;
	cin >> N >> S;

	string now_wordsline = "b";
	bool is_yes = false;
	for(int i=0; i<100; i++)
	{
		if (now_wordsline == S) {
			//dump(now_wordsline);
			//dump(S);
			is_yes = true;
			cout << i << endl;
			break;
		}

		int ii = i % 3;
		
		//dump(ii);
		if (ii == 0) {
			now_wordsline = "a" + now_wordsline + "c";
		}
		else if (ii == 1) {
			now_wordsline = "c" + now_wordsline + "a";
		}
		else if (ii == 2) {
			now_wordsline = "b" + now_wordsline + "b";
		}
	}
	if (!is_yes) {
		cout << -1 << endl;
	}


	return EXIT_SUCCESS;
}
