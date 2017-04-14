#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#define dump(a) cout << (#a) << "=" << (a) << endl

using namespace std;
string list_token="alistof"; //a list of
string and_token="and";

struct Node {
	vector<Node> nodes;
};

string expr_1(const string &line, int &i, Node &root, bool &is_nega);
string expr_2(const string &line, int &i, Node &root, bool &is_nega);
string expr(const string &line, int &i, Node &root, bool &is_nega);

/*
//子供が1つであるのあとに,その孫が2つ以上
void search(Node &root, int &cnt) {
	//cout << root.nodes.size() << endl;
	if (root.nodes.size() == 1) {
		if (root.nodes[0].nodes.size() >= 2) { is_AMBIGUOUS = true; return; }
	}

	for(auto child : root.nodes) {
		search(child,cnt);
	}
}
*/

string alpha(const string &line, int &i) {
	string res="";
	while('A' <= line[i] && line[i] <= 'Z') {
		res+=line[i];
		i++;
	}
	return res;
}

bool is_next_alpha(const string &line, int i) { //iはその場のみ
	return 'A' <= line[i] && line[i] <= 'Z';
}

bool is_next_expr(const string &line, int i) { //iはその場のみ
	return line[i] == ',';
}


/*
 * 優先度合いを変える
 */
/*
bool nega_posi(const string &line, int &i, bool &is_nega) {
line.find(and_token,i) != string::npos
}
*/


//a list of <expr> <expr>* and <expr>
string expr_1(const string &line, int &i, Node &root, bool &is_nega)
{
	string res="";
	Node aChild=Node();
	res += expr(line,i,aChild,is_nega);
	root.nodes.push_back(aChild);

	while (is_next_expr(line, i)) {
		++i;
		aChild = Node();
		res += " " + expr(line,i,aChild,is_nega);
		root.nodes.push_back(aChild);
	}

	if (line.substr(i,and_token.size()) == and_token) {
		i+=and_token.size();
		aChild = Node();
		res += " " + expr(line,i,aChild,is_nega);
		root.nodes.push_back(aChild);
	}
	return res;
}

//a list of <expr>
string expr_2(const string &line, int &i, Node &root, bool &is_nega) {
	string res="";
	Node aChild=Node();
	res += expr(line,i,aChild,is_nega);
	root.nodes.push_back(aChild);

	return res;
}

string expr(const string &line, int &i, Node &root, bool &is_nega)
{
	if (line.substr(i,list_token.size()) == list_token)
	{
		i+=list_token.size(); //a list of を飛ばす
		string res = "(";

		//expr1とexpr2の優先度を無理やり変更する
		if (is_nega) {
			if (line.find(and_token,i) != string::npos) {
				res+=expr_1(line,i,root,is_nega);
			}
			else {
				res+=expr_2(line,i,root,is_nega);
			}
		}
		else {
			if (line.find(and_token,i) == string::npos) {
				res+=expr_2(line,i,root,is_nega);
			}
			else {
				res+=expr_1(line,i,root,is_nega);
			}
		}
		res += ")";

		return res; //Here
	}
	else  {
		string c = alpha(line,i);
		return c;
	}
}

int main()
{
	//test
	/*
	string line="JUDGEMENTandACMICPCTK";
	int i=0;
	cout << alpha(line,i) << endl;
	*/

	int N;
	string num_str;
	getline(cin,num_str);
	N = stoi(num_str);

	for(int n=0; n<N; n++) {
		Node rootNode;
		string line,new_line="";
		getline(cin,line);
		for(int ii=0; ii<line.size(); ii++) { if (line[ii] != ' ') new_line+=line[ii]; }

		bool is_nega = true;
		int first_i = 0;
		string ans_line_1 = expr(new_line,first_i,rootNode,is_nega);
		is_nega = false;
		int second_i = 0;
		string ans_line_2 = expr(new_line,second_i,rootNode,is_nega);
		dump(ans_line_1);
		dump(ans_line_2);

		/*
		if (first_i == second_i && second_i == new_line.size()) { //両方辿り着いている
			if (ans_line_1!=ans_line_2) {
				cout << "AMBIGUOUS" << endl;
			}
		}
		else {
		}
		*/
		//cout << (ans_line_1==ans_line_2 ? ans_line_1:"AMBIGUOUS") << endl;
	}

	return EXIT_SUCCESS;
}
