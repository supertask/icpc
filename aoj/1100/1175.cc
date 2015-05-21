#include<bits/stdc++.h>
#define dump(a) cerr << #a << "=" << (a) << endl

using namespace std;

struct Circle {
	int x;
	int y;
	int r;
	int color;
	int pat; //top_circlesの代わり
	vector<Circle> top_circles; // top circles
};


template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for(int i=0; i < v.size(); i++) {
		if (i > 0) { os << ", "; }
		os << v[i];
	}
	return os;
}



void dfs(vector<Circle> circles, )
{
	vector<vector<int> > same_colors(4,vector<int>);
	for(int cir=0; cir<circles.size(); cir++)
	{
		//上に何もない時,同じ色やったらチョイス出来る
		if (circles[cir].pat == 0) {
			int color = circles[cir].color;
			same_colors[color].push_back(cir);
		}
	}
	for(int i=0; i<same_colors.size(); i++) {
		same_color = same_colors[i];
		if (same_color.size() >= 2) {
			
		}
	}

	/*
	for(int c=1; c<=4; c++) {
		for(int cirL=1; cirL<=4; cirL++) {
			for(int cirR=1; cirR<=4; cirR++) {
				
			}
		}
	}
	*/
}



int main() {
	int N;
	int x,y,r,color;


	while(cin >> N)
	{
		if (N == 0) { break; }
		vector<Circle> circles;
		for(int i=0; i<N; i++) {
			cin >> x >> y >> r >> color;
			Circle c;
			c.x = x;
			c.y = y;
			c.r = r; 
			c.color = color;
			//下のレイヤーの初期化は飛ばす

			circles.push_back(c);
		}

		for(int i=0; i<N; i++) {
			for(int j=i-1; j >= 0; j--) {
				//j = 自分の円より上の円
				//i = 自分の円
				int diff_x = abs(circles[j].x - circles[i].x);
				int diff_y = abs(circles[j].y - circles[i].y);
				int d = sqrt(diff_x*diff_x+diff_y*diff_y);
				d = d - circles[i].r - circles[j].r; //円と円の間の隣接距離
				if (d < 0) { //重なっている
					circles[i].pat += (1 << j);
					//circles[i].top_circles.push_back(circles[j]);
				}
			}
		}


		cout << "TestCase " << N << endl;
		for(int i=0; i<N; i++) {
			cout << "circle " << i << endl;
			//printf("\t%d %lu\n",circles[i].pat,circles[i].top_circles.size());
			printf("\t%d\n",circles[i].pat);
			/*
			for (int j = 0; j < circles[i].top_circles.size(); j++) {
				Circle c = circles[i].top_circles[j];
				//printf("\t%d %d %d %d\n",c.x,c.y,c.r,c.color);
				//printf("\t%d %lu\n",c.pat,c.top_circles.size());
				//printf("\t%d\n",c.pat);
			}
			*/
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}
