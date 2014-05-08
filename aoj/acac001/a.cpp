/* AC */
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(), (c).end()
#define MOD 1000000007 
using namespace std;

int main() {
	int n;
	long m,answer;
	bool bit_n[32];
	int max_bit = 0;

	cin >> m >> n;
		
	rep(i,32) {
		bit_n[i] = (n & 1);
		if (bit_n[i]) { max_bit = i; }
		n>>=1;
	}
	
	/*
	 * バイナリ法
	 * 3^1 3^2 3^4 3^8  3^16     3^32
	 * 3   9   81  6561 43046721 1853020188851841
	 * これが，mの値に置き換わり，
	 * 3^43を計算するなら，3^43 = 3^32 * a^8 * a^2 * a^1
	 * これを計算する．
	 * このとき，mはintの容量を超えるので，
	 * m = m % 1000000007
	 * によって，intを超えないように設定する．
	 * また，answerも同様にし，答えを導く．
	 * 
	 */
	answer = 1;
	rep(i,max_bit+1) {
		if (m >= MOD) { m = m % MOD; }
		if (answer >= MOD) { answer = answer % MOD; }
		if (bit_n[i]) { 
			answer *= m; 
		}
		m *= m;
	}
	cout << answer % MOD << endl;

	return 0;
}
