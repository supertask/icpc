#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;

#define INF 1000000 //1e18

/*
 * 1~9			1桁 9*1 			= 9文字目(文字インデックス番号)
 * 10~99 		2桁 9 + 90*2 		= 189文字目
 * 100~999 		3桁 189 + 900*3		= 2889文字目
 * 1000~9999 	4桁 2889 + 9000*4 	= 38889文字目
 * 10000~99999	5桁 38889 + 90000*5 = 488889文字目
 */

int main() {
	unsigned long long aho_c=0,dog_c=0,rm_nabeatu=0; //アホ=3,犬=5
	unsigned long long N; //2**64(20桁)
	unsigned long long range=1; //数字の文字列数を求めるためのもの
	unsigned long long str_index=0;
	unsigned long long back_str_index=0;
	unsigned long long real_str_index=0;
	unsigned long long keta_max=0;
	unsigned long long nabeatu=0;
	int keta_num = 1;

	cin >> N;

	while(true) {
		if (real_str_index > INF) { break; }
		//cout << range << " " << range*10-1 << endl;
		str_index += (range*10 - range)*keta_num;

		if (back_str_index <= N && N < str_index) //9~189,189~2889
		{
			unsigned long long diff_N = N+1-range;
			
			real_str_index = back_str_index + diff_N*keta_num; //数字のみ
			dump(real_str_index); //41

			real_str_index -= (rm_nabeatu + (N/3 - aho_c)*keta_num + (N/5 - dog_c)*keta_num);	
			real_str_index += aho_c + dog_c;
			//dump(back_str_index);
			dump(real_str_index);
			break;
		}

		aho_c = (range*10-1) / 3;
		dog_c = (range*10-1) / 5;
		nabeatu += aho_c*keta_num + dog_c*keta_num;
		str_index2 = str_index + nabeatu - ; //Her

		back_str_index = str_index;
		range *= 10;
		++keta_num;
	}


	//cout << aho_c << " " << dog_c << endl;

	return 0;
}
