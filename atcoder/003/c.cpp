#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;
int N,M;
vector<double> lights;
char chars[500][500];
bool isVisit[500][500];
bool isGoal;
int dm[] = {-1,0,1,0};
int dn[] = {0,-1,0,1};
typedef struct neighbor {
	int m;
	int n;
	int light;
	bool operator<( const neighbor& right ) const {
		return light > right.light;
	}
} Neighbor;

void check_neighbor(int m, int n) 
{
	isVisit[m][n] = true;	
	vector<Neighbor> neis;

	rep(i,4) {
		int am = m + dm[i];
		int an = n + dn[i];
		if (0 <= an && an < N && 0 <= am && am < M && isVisit[am][an] == false) 
		{
			if (chars[am][an] == 'g') {
				isGoal = true;			
				return;
			}
			else if (chars[am][an] == '#') {
				return;
			}
			else {
				Neighbor nei;
				nei.m = am;
				nei.n = an;
				nei.light = chars[am][an] - '0';
				neis.push_back(nei);
			}
		}
	}
	sort(all(neis));
	rep(i,neis.size()) {
		cout << "m = " << neis[i].m << " n = " << neis[i].n;	
		cout << " light " << neis[i].light << endl;	
		if (isGoal == false || isVisit[neis[i].m][neis[i].n] == false) {
			check_neighbor(neis[i].m,neis[i].n);
		}
	}
	neis.clear();

	return;
}

int main() {
	string a_str;
	int start_n, start_m;

	isGoal = false;
	cin >> N >> M;

	rep(n,N) {
		cin >> a_str;
		rep(m,M) {
			chars[m][n] = a_str[m];
			if (chars[m][n] == 's') {
				start_n = n;
				start_m = m;
			}
		}
	}
	check_neighbor(start_m, start_n);

	rep(i,lights.size()) {
		lights[i] = lights[i] * pow(0.99,i+1);	
		cout << "lights[" << i <<  "] = " << lights[i] << endl;
	}
	if (isGoal) {
		cout << setprecision(9);
		cout << *min_element(all(lights)) << endl;
		cout << setprecision(6);
	}
	else {
		cout << "-1" << endl;	
	}

	return 0;
}

