/*
 * 国内予選2014 B問題【連鎖消滅パズル（パズドラ）】
 * 担当：高橋 今江
 */
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<iomanip>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{"; for(auto nth : list){ cout << nth << " ";}cout << "}" << endl;

using namespace std;

int pazu[5][10];
int ans;

void init(int H)
{
	ans=0;
	rep(h,H){
		rep(w,5){
			pazu[w][h]=0;
		}
	}
}

int main(){
	
	int H;
	while(cin >> H && H)
	{
		init(H);
		rep(h,H)
		{
			rep(w,5)
			{
				cin >> pazu[w][h];
			}
		}

		int ans=0;
		bool is_three=false;

		while(true)
		{
			rep(h,H) {
				int back_num=0;
				vector<int> same_widthes;
				rep(w,5){
					same_widthes.push_back(w); //w
					back_num = pazu[w][h];
					REP(ww,w+1,5) {
						if (back_num == pazu[ww][h] && (back_num!=0)) { 
							same_widthes.push_back(ww);
							back_num = pazu[ww][h];
						}
						else { break; }
					}
					if (same_widthes.size()>=3) {
						rep(i,same_widthes.size()) {
							ans += same_widthes[i];
							pazu[same_widthes[i]][h] = 0;
						}
						is_three = true;
					}
					same_widthes.clear();
					back_num=0;
				}
			}

			cout << "before--------------" << endl;
			rep(h,H){rep(w,5){cout << pazu[w][h] << " ";}cout << endl;}

			//下にずらす
			rep(w,5) {
				int swap = 0;
				int under_i = 0;
				int i = 0;
				while(true) {
					if (i>H) {break;}
					if (pazu[w][under_i] != 0) { //下に数字があるとき
						under_i++;
						i++;
					}
					else { //下が0
						i++;
						if (pazu[w][i] != 0) { //下に数字がなくて，上に数字があるとき
							cout << i << " " << under_i << endl;
							swap = pazu[w][i]; //iは上の玉
							pazu[w][i] = 0;
							pazu[w][under_i] = swap;
							under_i++;
							i=under_i;
						} 
					}
				}
			}

			cout << "after--------------" << endl;
			rep(h,H){rep(w,5){cout << pazu[w][h] << " ";}cout << endl;}

			//ずっとis_three状態
			if (!is_three) { break; } //3つ以上一緒のが見つからないとき
			is_three = false;
		}
	}
	return 0;
}
