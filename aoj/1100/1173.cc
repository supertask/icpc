#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
using namespace std;

/*
	expr:
		| ''
		| term expr
	term: 
		| '(' expr ')' 
		| '[' expr ']'
*/

bool isCheck=true;

void term(string &line, int &i);
void expr(string &line, int &i);

void term(string &line, int &i)
{
	switch(line[i])
	{
		case '(':
			i++;
			expr(line, i);
			if (line[i] != ')') { isCheck=false; }
			i++;
			break;
		case '[':
			i++;
			expr(line, i); //iにはアルファベット
			if (line[i] != ']') { isCheck=false; }
			i++;
			break;
		default:
			break;
	}
	return;
}


/*
	expr:
		| ''
		| term expr
	term: 
		| '(' expr ')' 
		| '[' expr ']'
*/


void expr(string &line, int &i)
{
	if (line[i] == '(' || line[i] == '[') {
		term(line,i);
		expr(line,i);
	}
	return; //空文字
}

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

int main()
{
	string line;
	while(getline(cin, line)) {
		isCheck=true;
		if (line[0] == '.') { break; }
		//cout << line << endl;
		int i=0;
		string new_line=pass(line);
		if (new_line[0]==')' || new_line[0]==']') {
			isCheck=false;
		}
		else {
			expr(new_line,i);
		}

		cout << (isCheck ? "yes":"no") << endl;
	}

	return EXIT_SUCCESS;
}
