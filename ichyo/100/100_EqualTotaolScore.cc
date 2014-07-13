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

int main() {
	int N,M;
	while(cin >> N >> M && N && M) {
		int num;
		int sum_taro=0,sum_hana=0;
		vector<int> taro,hana;

		rep(i,N) {
			cin >> num;	
			sum_taro += num;
			taro.push_back(num);
		}
		rep(i,M) {
			cin >> num;	
			sum_hana += num;
			hana.push_back(num);
		}
		
		bool is_yes=false;
		vector<int> ok_taros,ok_hanas,ok_sums;
		rep(i,N) { //taro
			rep(j,M) { //hana
				int sum_taro_tmp = sum_taro - taro[i] + hana[j];
				int sum_hana_tmp = sum_hana - hana[j] + taro[i];
				if (sum_taro_tmp == sum_hana_tmp) { 
					is_yes = true; 
					ok_taros.push_back(taro[i]);
					ok_hanas.push_back(hana[j]);
					ok_sums.push_back(taro[i]+hana[j]);
				}
			}
		}
		if (is_yes) { 
			int tmp_i;
			int mini=INT_MAX;
			rep(i,ok_sums.size()) {
				if (ok_sums[i] <= mini) {
					mini = ok_sums[i];
					tmp_i = i;
				}
			}
			cout << ok_taros[tmp_i] << " " << ok_hanas[tmp_i] << endl;
		}
		else { cout << "-1" << endl; }
	}

	return 0;
}
