#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#include<cctype>
#define dump(a) cout << (#a) << "=" << (a) << endl

using namespace std;

struct Node {
	string alpha;
	int num; //数値1~
	vector<Node> children;

	Node(): alpha("@"), num(-1) {}

};

void dfs_show(Node &root, int level) {
	dump(level);
	if (root.num != -1) { dump(root.num); }
	if (root.alpha != "@") { dump(root.alpha); }
	for(auto &child : root.children) {
		dfs_show(child, level + 1);
	}
}


string read_alphas(const string &line, int &i) {
	string res_alphas="";
	if (isalpha(line[i])) {
		res_alphas += line[i];
		i++;
		res_alphas += read_alphas(line,i);
	}
	return res_alphas;
}

string read_digits(const string &line, int &i) {
	string res_digits="";
	if (isdigit(line[i])) {
		res_digits += line[i];
		i++;
		res_digits += read_digits(line,i);
	}
	return res_digits;
}

Node expr(const string &line, int &i, Node root)
{
	if (isdigit(line[i]))
	{
		Node oneNode,twoNode;
		int num = stoi(read_digits(line,i));
		if (line[i] == '(') { i++; }
		oneNode = expr(line,i,Node());
		oneNode.num = num;
		//dump(oneNode.num);
		root.children.push_back(oneNode);

		if (line[i] == ')') { i++; }
		twoNode = expr(line,i,Node());
		dump(twoNode.num);

		if ( !(twoNode.alpha == "@" && twoNode.num == -1)) {
			root.children.push_back(twoNode);
		}
	}
	else if (isalpha(line[i])) {
		Node oneNode;
		oneNode.alpha = read_alphas(line,i);
		Node twoNode = expr(line,i,Node());
		root.children.push_back(oneNode);
		if ( !(twoNode.alpha == "@" && twoNode.num == -1)) {
			root.children.push_back(twoNode);
		}
	}
	else {
		//EMPTY 何もしない
	}

	return root;
}

int main() {
	string line;
	int N;
	while(cin >> line >> N) {
		if (line[0]=='0' && N == 0) { break; }
		Node root;
		int i=0;
		root=expr(line,i,root);
		int level=0;
		dfs_show(root,level);
	}

	return EXIT_SUCCESS;
}
