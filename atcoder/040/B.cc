#include<bits/stdc++.h>
#define dump(a) cout << (#a) << "=" << (a) << endl
#define numof(array)  (sizeof (array) / sizeof *(array))

using namespace std;

int main() {
	int N,R;
	string line;

	cin >> N >> R >> line;

	int ans=0;
	int gun_cnt=0;
	int first_i = line.find_first_of('.',0);
	int last_i = line.find_last_of('.',N-1) + 1;
	//cout << first_i << endl;
	//cout << last_i-R << endl;
	for(int i=first_i; i<=last_i-R; i++)
	{
		int paint_cnt = count(line.begin()+i,line.begin()+i+R,'o');
		if (paint_cnt != R) {
			gun_cnt++;
			fill(begin_iterator, end_iterator,'o');
			//dump(line);
			ans = i+gun_cnt;
		}
	}
	cout << ans << endl;

	return EXIT_SUCCESS;
}
