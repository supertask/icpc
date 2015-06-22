#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#define dump(a) cout << (#a) << "=" << (a) << endl

using namespace std;
string token_first="a list of ";
string token_middle="and";

string alphaX(const string &line, int &i) {
	i++;
	assert('A' <= line[i] && line[i] == 'Z');
	return string(1,line[i]);
}

string expr(const string &line, int &i)
{
	string a_str = line.substr(i,token_first.size());
	if (line.substr(i,token_first.size()) == token_first)
	{
		i+=token_first.size();
			

		return ""; //Here		
	}
	else {
		return alphaX(line,i);
	}
}

int main()
{
	int N;
	string num_str;
	getline(cin,num_str);
	N = num_str[0]-'0';

	for(int n=0; n<N; n++) {
		int i = 0;
		string line;
		getline(cin,line);
		cout << expr(line,i) << endl;
	}

	return EXIT_SUCCESS;
}
