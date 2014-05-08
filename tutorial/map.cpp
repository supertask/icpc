#include <iostream>
#include <map>
using namespace std;

int main()
{
	// charをキー、intを値として扱う連想配列
	map<char, int> a_map;
	
	// 挿入
	a_map.insert(make_pair('c', 30));
	a_map.insert(make_pair('a', 10));
	a_map.insert(make_pair('b', 20));
	
	// 検索 : キー(char)を指定し、値(int)を得る
	int value = a_map.at('a');
	int count = a_map.count('b');
	cout << value << endl;

	return;
}

