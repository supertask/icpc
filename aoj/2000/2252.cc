#include<bits/stdc++.h>
#define dump(a) cout << #a << "=" << a << endl
using namespace std;

char left_key[15] = {
	'q','w','e','r','t', 
	'a','s','d','f','g',
	'z','x','c','v','b'
};
char right_key[11] = {
	'y','u','i','o','p',
	'h','j','k','l',
	'n','m'
};

bool is_word(string word) {
	return false;
}

int main() {
	string word;
	while(cin >> word) {
		if (word[0] == '#') { break; }

		int back = 0;
		int now = 0;
		int cnt=0;
		for(int i = 0; i < word.size(); i++) {
			//cout << word[i] << endl;
			for(int j = 0; j < 15; j++) {
				if (left_key[j] == word[i]) {
					now = 1;
				}
			}
			for(int j = 0; j < 11; j++) {
				if (right_key[j] == word[i]) {
					now = 2;
				}
			}
			//cout << "now: " << now << endl;
			if (now != back) { cnt++; }
			back = now;
		}
		cout << (cnt-1) << endl;

	}

	return EXIT_SUCCESS;
}
