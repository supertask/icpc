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
#define POINT_N 4
using namespace std;
int x[POINT_N],y[POINT_N];

double line_len(int l, int r) {
	return sqrt(pow(x[l] - x[r],2) + pow(y[l] - y[r],2)); 
}

double heron(double a, double b, double c) {
	double s;
	s = (a + b + c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
	int q;
	double center;
	double s1,s2;
	double ans_x,ans_y;

	cin >> q;
	cout << setprecision(10) << fixed;
	rep(i,q) {
		rep(j,POINT_N) {
			cin >> x[j] >> y[j];
		}
		center = line_len(0,1);
		s1 = heron(line_len(0,2), line_len(1,2), center);
		s2 = heron(line_len(3,0), line_len(3,1), center);
		ans_x = x[2] + ((x[3] - x[2]) * s1 / (s1 + s2));
		ans_y = y[2] + ((y[3] - y[2]) * s1 / (s1 + s2));
		cout << ans_x << " " << ans_y << endl;
	}

	return 0;
}
