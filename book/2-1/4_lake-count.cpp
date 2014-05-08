##include<iostream>
using namespace std;

int M,N;
char map[100][100];
bool isVisit[100][100]={false};

int search(int m, int n) {
	int am,an;
	isVisit[m][n] = true;
	int lakeSize = 1;
	for (int dn=-1; dn<=1; dn++) {
		for (int dm=-1; dm<=1; dm++) {
			am = m+dm;
			an = n+dn;
			if (0 <= am && am <= M && 0 <= an && an <= N) {
				if (map[am][an]=='W' && isVisit[am][an]==false) {
					lakeSize += search(am,an);
				}
			}
		}
	}
	return lakeSize;
}

int main() {
	cin >> N >> M;
	int count=0;
	for (int n=0; n<N; n++) {
		for (int m=0; m<M; m++) {
			cin >> map[m][n];
		}
	}
	for (int n=0; n<N; n++) {
		for (int m=0; m<M; m++) {
			if (map[m][n]=='W' && isVisit[m][n]==false)
			{
				search(m,n);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
