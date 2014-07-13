#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()

using namespace std;

char alphas[26];

char get_moder(char first_char, int count) {
	int index = first_char - 'A';
	while(count < 0) { count+=26; }
	return alphas[(index+count) % 26];
}

int main() {
	string a_str;

	rep(i,26) {
		alphas[i] = (char)('A'+i);
	}
	//cout << get_moder('Z',2) << endl;

	while(cin >> a_str) {
		if (a_str[0] == '.') { break; }
		int next_cnt=0;
		vector<int> moji_cnt;
		vector<string> mojis;
		moji_cnt.push_back(0);

		rep(i,a_str.size()) 
		{
			if ('A' <= a_str[i] && a_str[i] <= 'Z') {
				string tmp_str = string(1,get_moder(a_str[i],next_cnt));
				mojis.push_back(tmp_str);
				moji_cnt[moji_cnt.size()-1]++;
				next_cnt = 0;
			}
			else if (a_str[i] == '?') {
				mojis.push_back("A");
				moji_cnt[moji_cnt.size()-1]++;
				next_cnt = 0;
			}
			else if (a_str[i] == '+') {
				next_cnt++;
			}
			else if (a_str[i] == '-') {
				next_cnt--;
			}
			else if (a_str[i] == '[') {
				moji_cnt.push_back(0);
			}
			else if (a_str[i] == ']') {
				string tmp_str="";
				int num = moji_cnt.back();
				moji_cnt.pop_back();

				rep(i,num) {
					tmp_str += mojis.back();
					mojis.pop_back();
				}
				reverse(all(tmp_str));
				moji_cnt[moji_cnt.size()-1]++;
				mojis.push_back(tmp_str);
			}
		}
		if (moji_cnt.size() > 0) {
			int num = moji_cnt.back();
			moji_cnt.pop_back();
			string tmp_str="";
			rep(i,num) {
				tmp_str += mojis.back();
				mojis.pop_back();
			}
			reverse(all(tmp_str));
			cout << tmp_str << endl;
		}
	}

	return 0;
}
