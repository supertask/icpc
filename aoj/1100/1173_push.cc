#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;

stack<char> store;

string pass(string &line)
{
	string new_line;
	for(int i=0; i<line.size(); i++) {
		if ((line[i] == '[') || (line[i] == '(') ||
			(line[i] == ']') || (line[i] == ')') ) {
			new_line+=line[i];
		}
	}
	return new_line;
}


void popper(bool &isCheck) {
}

int main() {
	string line;
	while(getline(cin, line))
	{
		if (line[0] == '.') { break; }
		bool isCheck=true;
		string new_line=pass(line);
		for(int i=0; i<new_line.size(); i++) {
			//dump(i);
			//dump(new_line[i]);
			if(new_line[i] == '[' || new_line[i] == '(') {
				store.push(new_line[i]);
			}
			else if(new_line[i] == ']') {
				if (store.size() == 0) { isCheck=false; }
				char value = store.top();
				store.pop();
				if (value != '[') {
					isCheck=false;
					continue;
				}
			}
			else if(new_line[i] == ')') {
				if (store.size() == 0) {
					isCheck=false;
					continue;
				}
				char value = store.top();
				store.pop();
				if (value != '(') {
					isCheck=false;
				}
			}
		}

		cout << (isCheck ? "yes":"no") << endl;
	}

	return EXIT_SUCCESS;
}
