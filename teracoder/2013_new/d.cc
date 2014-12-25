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


int main() {
	int T,N,M;
	cin >> T;
	rep(t,T)
	{
		vector<vector<char> > jans(11,vector<char>(101,0));
		vector<int> jan_point(11,0);

		cin >> N >> M;
		rep(m,M) {
			rep(n,N) {
				cin >> jans[n][m];
			}
		}
		
		rep(m,M) {
			//ラウンド
			char jan_kind[3] = {'g','c','p'};
			bool jan_tmp[3] = {false,false,false};
			rep(n,N) {
				//じゃんけんする人
				rep(i,3) {
					if (jans[n][m] == jan_kind[i]) {
						jan_tmp[i]=true;
					}
				}
			}

			if (jan_tmp[0] && jan_tmp[1] && jan_tmp[2]) { //あいこ
			}
			else if (jan_tmp[0] && jan_tmp[1]) { //gで勝つ
				rep(n,N) { 
					if (jans[n][m] == 'g') { jan_point[n]++; }
				}
			}
			else if (jan_tmp[1] && jan_tmp[2]) { //cで勝つ
				rep(n,N) { 
					if (jans[n][m] == 'c') { jan_point[n]+=2; }
				}
			}
			else if (jan_tmp[2] && jan_tmp[0]) { //pで勝つ
				rep(n,N) { 
					if (jans[n][m] == 'p') { jan_point[n]+=2; }
				}
			}
		}

		int maxi = *max_element(ALL(jan_point));
		string ans_line="";
		rep(n,N) {
			if (jan_point[n] == maxi) {
				ans_line += to_string(n+1)+" ";
			}
		}
		ans_line.pop_back();
		cout << ans_line << endl;
		
	}

	return 0;
}
