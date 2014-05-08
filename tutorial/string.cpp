#include<iostream>
using namespace std;

int main() 
{
	/*
	 * 一文字ずつ取り出し 
	 */
	char chars[] = "abcdefg";
	string str = string(chars);
	for (int i = 0; i < (int)str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	/*
	 * スプリット
	 */ 
	char *tok = strtok(chars,"cd");
	while ( tok != NULL ) {
		cout << "split: " << tok << endl;
		tok = strtok( NULL,"cd");
	}

	/* 文字列比較 */
	if (str == "abcdefg") {
		cout << "完全一致" << endl;
	}

	/*
	 * 文字列カット
	 * param どの要素から
	 * [param どの要素まで]
	 */
	string str_cut = str.substr(3,2);
	cout << "カット " << str_cut << endl; 

	/* 
	 * マッチ検査
	 * npos = 見つからなかったとき 
	 */
	string compile_str = "cd";
	string::size_type index = str.find(compile_str);
	if (index != string::npos) {
		cout << "マッチ: " << str.substr(index,compile_str.size()) << endl;
	}
	while (index != string::npos) {
		cout << index << endl;
		index = str.find(compile_str,index + 1);
	}

	return 0;
}

