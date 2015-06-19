#include<bits/stdc++.h>
#define dump(a) cout << (#a) << " " << a << endl
#define STUDENT_NUM 10000
using namespace std;

vector<vector<pair<int,int>>> students(STUDENT_NUM+1,vector<pair<int,int>>());

int main()
{
	int N,M,R;
	cin >> N >> M >> R;

	int  t,n,m,s;
	
	for(int i=0; i<R; i++) {
		cin >> t >> n >> m >> s;
		vector<pair<int,int>> aStudent = students[m];


		if (s) { aPair.first=t; } //ログイン
		else { aPair.second=t; }
		students[m].push_back();
	}

	return EXIT_SUCCESS;
}
