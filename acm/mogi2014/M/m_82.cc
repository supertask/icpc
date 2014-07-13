/*
 * I'm @pythor.
 * I love Zentansaku. and team name is { Zentan Onii }.
 */

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

#define ZENTAN_ONII 82 /* 0 <= ZENTAN_ONII < 16 */
#define RANGE 8

using namespace std;


void print_zentan(bool is_A) {
	if (is_A) {
		cout << "Set A" << endl;
	}
	else {
		cout << "Set B" << endl;
	}
}


int main() 
{
	// 8 pattern
	int x = ZENTAN_ONII;
	bool data[RANGE];
	rep(i,RANGE) {
		data[i] = x & 1;
		cout << data[i];
		x >>= 1;
	}
	cout << endl;

	int N;
	while(cin >> N && N)
	{
		switch(N)
		{
			case 1:
				cout << "Set A" << endl; //OK
				break;
			case 2:
				cout << "Set B" << endl; //OK
				break;
			case 3:
				cout << "Set B" << endl; //OK
				break;
			// Adding Begin

			case 49:
				cout << "Set A" << endl; //OK
				break;
			case 50:
				cout << "Set A" << endl; //OK
				break;
			case 51:
				cout << "Set A" << endl; //OK
				break;
			case 52:
				cout << "Set B" << endl; //OK
				break;
			//Adding End

			case 98:
				cout << "Set B" << endl; //OK
				break;
			case 99:
				cout << "Set A" << endl; //OK
				break;
			case 100:
				cout << "Set B" << endl; //OK
				break;
		}
	}

	return 0;
}
