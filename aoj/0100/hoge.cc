#include<bits/stdc++.h>
/*
#include<array>
#include<vector>
#include<iostream>
#include<cmath>
*/

using namespace std;

typedef double Real;
constexpr Real EPS = 1e-8;

enum { CCW=1, CW = -1, BACK= 2, FRONT=-2, ON=0}; //Counter Clock Wise

//誤差修正
int sign(Real d) {
	if (d>EPS) { return 1; }
	if (d<-EPS) { return -1; }
	return 0;
}


/*
 * 点の構造体定義
 */
struct Point {
	Real x,y;

	//Point p(2,3)は許可
	explicit Point(Real x_=0, Real y_=0): x(x_), y(y_) {} //explicitは代入Point p = x;が許可されていしまう

	Point operator+(const Point &p) const {
		return Point(x+p.x,y+p.y);
	}
	Point operator-(const Point &p) const {
		return Point(x-p.x,y-p.y);
	}
	Point operator*(Real s) const {
		return Point(x*s,y*s);
	}
	Point operator/(Real s) const {
		return Point(x/s,y/s);
	}
	bool operator<(const Point &p) const {
		return sign(x - p.x) == -1 || (sign(x - p.x)==0 && sign(y - p.y)==-1);
	}
	bool operator==(const Point &p) const { return sign(x-p.x) == 0 && sign(y - p.y)==0; }

};

//Pointのデバッグオペレータ
istream &operator>>(istream &is, Point &p) {
	return is >> p.x >> p.y;
}
ostream &operator<<(ostream &os, const Point &p) {
	//return os << '(' << p.x << ", " << p.y << ')';
	return os << p.x << " " << p.y;
}

struct Line : public array<Point, 2> { //線分
	Line(const Point &a, const Point &b) { at(0) = a; at(1) = b; }
};

struct Segment : public array<Point, 2> { //直線
	Segment(const Point &a, const Point &b) { at(0) = a; at(1) = b; }
};

/*
 *円
 */
struct Circle {
	Point c;
	Real r;
	Circle(const Point &c_, Real r_): c(c_), r(r_) {}
};

/*
 * 多角形
 */
typedef vector<Point> Polygon;



/*
 * Calc
 */
//反時計回り（90度）
Point rotate90(const Point &p) { return Point(-p.y,p.x); }

//反時計回り（自由）
Point rotate(const Point &p, Real theta) {
	const Real s = sin(theta), c = cos(theta);
	return Point(c*p.x - s*p.y, s*p.x + c*p.y);
}

//[X軸]と[原点から点Pの線]の角度
Real angle(const Point &p) { return atan2(p.y, p.x); }

//原点0からの点Pまでの距離の２乗
Real norm(const Point &p) { return p.x * p.x + p.y * p.y; }

//原点0からの点Pまでの距離
Real abs(const Point &p) { return sqrt(norm(p)); }

//内積外積
Real dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; } //内積(ルートは取っている)
Real cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; } //外積

 //射影
Point project(const Line &l, const Point &p) {
	const Point a = p - l[0];
	const Point b = l[1] - l[0];
	return l[0] + b * (dot(a,b) / norm(b));
}
//線対称
Point reflect(const Line &l, const Point &p) {
	const Point t = project(l, p);
	return t + (t-p);
}

//Counter Clock Wise
int ccw(const Point &a, const Point &b, const Point &c) { //時計のどの状態か
	const Point p = b - a;
	const Point q = c - a;
	const Real cr = cross(p,q);

	if (sign(cr) == 1) { return CCW; }
	if (sign(cr) == -1) { return CW; }
	if (sign(dot(p,q)) == -1) { return BACK; }
	if (sign(norm(p) - norm(q)) == -1) { return FRONT; }
	return ON;
}

//交差判定
bool intersect(const Segment &s, const Point &p) {
	return ccw(s[0], s[1], p) == ON;
}

bool intersect(const Segment &a, const Segment &b) { //重なっているかどうか
	return ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]) <= 0 
		   && ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]) <=0;
}

bool intersect(const Line &l, const Point &p) { //
	return abs(ccw(l[0], l[1], p)) != 1;
}

bool intersect(const Line &l, const Segment &s) { //
	return sign(cross(l[1] - l[0], s[0] - l[0]) * cross(l[1] - l[0], s[1] - l[0])) <=0;
}

bool intersect(const Line &a, const Line &b) { 
	return sign(cross(a[1]-a[0], b[1]-b[0])) != 0
		|| sign(cross(a[1]-a[0], b[1]-a[0])) == 0;
}


//距離
Real dist(const Point &a, const Point &b) {
	return abs(a - b);
}
Real dist(const Line &l, const Point &p) {
	Point a = l[1] - l[0];
	Point b = p - l[0];
	return abs(cross(a,b))/abs(a);
}
Real dist(const Line &l, const Segment &s) {
	if (intersect(l,s)) { return 0; }
	return min(dist(l,s[0]), dist(l,s[1]));
}
Real dist(const Line &a, const Line &b) {
	if (intersect(a,b)) { return 0; }
	return dist(a,b[0]);
}
Real dist(const Segment &s, const Point &p) {
	if (sign(dot(s[1] - s[0], p - s[0])) == -1) { return dist(s[0],p); } 
	if (sign(dot(s[0] - s[1], p - s[1])) == -1) { return dist(s[1],p); } 
	return dist(Line(s[0],s[1]), p);
}

Real dist(const Segment &a, const Segment &b) {
	if (intersect(a,b)) { return 0; }
	return min({dist(a,b[0]), dist(a,b[1]), dist(b,a[0]), dist(b,a[1])});
}

//円が完全一致のときも弾く
bool intersect(const Circle &a, const Circle &b) {
	return sign(dist(a.c,b.c) - (a.r + b.r)) <= 0
		&& sign(dist(a.c,b.c) - abs(a.r - b.r)) >= 0;
}

bool intersect(const Circle &c, Segment &s) {
	return sign(dist(s, c.c) - c.r) <= 0;
}

bool intersect(const Circle &c, Line &l) {
	return sign(dist(l, c.c) - c.r) <= 0;
}


/*
 * 交点を求める
 */
Point crosspoint(const Line &a, const Line &b) {
	assert(intersect(a,b));
	const Real crs = cross(a[1] - a[0], b[1] - b[0]);
	if (sign(crs) == 0) { return a[0]; };
	return b[0] + (b[1] - b[0]) * (cross(a[1]-a[0], a[1]-b[0]) / crs);
}

//交点
Point crosspoint(const Segment &a, const Segment &b) {
	assert(intersect(a,b));
	
	const Real crs = cross(a[1] - a[0], b[1] - b[0]);
	if (sign(crs) == 0) {
		if(intersect(a, b[0])) { return b[0]; }
		if(intersect(a, b[1])) { return b[1]; }
		if(intersect(b, a[0])) { return a[0]; }
		return a[1];
	}
	return b[0] + (b[1] - b[0]) * (cross(a[1]-a[0], a[1]-b[0]) / crs);
}

vector<Point> crosspoint(const Circle &c, const Line &l) {
	const Point p = project(l,c.c);
	const Real h = dist(p,c.c);

	vector<Point> res;
	if(sign(h - c.r) == 1) {
		//nothing
	}
	else if (sign(h - c.r) == 0) {
		res.emplace_back(p);
	}
	else {
		const Real b = sqrt(c.r*c.r - h*h);
		const Point e = (l[1] - l[0]) / abs(l[1] - l[0]);
		res.emplace_back(p+e*b);
		res.emplace_back(p-e*b);
	}

	return res;
}

vector<Point> crosspoint(const Circle &c, const Segment &s) {
	vector<Point> res;
	for(const Point &p : crosspoint(c,Line(s[0],s[1]))) {
		if (intersect(s,p)) { res.emplace_back(p); }
	}
	return res;
}

vector<Point> crosspoint(const Circle &a, const Circle &b) {
	vector<Point> res;
	const Real d = dist(a.c,b.c);
	
	if (sign(d - (a.r + b.r)) == 1) {
		//nothing
	}
	else if (sign(d - (a.r + b.r)) == 0) {
		const Point v = b.c - a.c;
		res.emplace_back(a.c + (v * (a.r / abs(v))));
	}
	else {
		Real theta = acos((a.r*a.r + d*d - b.r*b.r) / (2 * a.r * d));
		const Real phi = angle(b.c - a.c);
		res.emplace_back(a.c + rotate(Point(a.r,0),phi+theta));
		res.emplace_back(a.c + rotate(Point(a.r,0),phi-theta));
	}
	
	return res;
}


bool contain(const Circle &c, const Point &p) {
	return sign(dist(c.c, p) - c.r) <= 0;
}

int contain(const Polygon &P, const Point &p) {
	bool res = false;

	for(int i=0; i<P.size(); i++) {
		Point v1 = P[i] - p;
		Point v2 = P[(i+1) % P.size()] - p;
		if (v1.y > v2.y) swap(v1,v2);
		if (sign(cross(v1,v2)) == 0 && dot(v1,v2) <= 0) {
			return 1; //辺上にあるとき
		}
		if (sign(v1.y) <= 0 && sign(v2.y) == 1 && sign(cross(v1,v2)) == 1) {
			res = !res;
		}
	}
	
	return res ? 2 : 0; //含まれるとき2, 含まれないとき0
}

Real area(const Polygon &P) {
	Real res = 0.0;
	for(int i = 0; i < P.size(); i++) {
		res += cross(P[i], P[(i+1)%P.size()]);
	}
	return abs(res) * 0.5;
}


/*
vector<Point> my_cp(const Circle &a, const Circle &b) {
	
}
*/


/*
 * Test Code
 */
int main() {
	//CCW=1, CW = -1, BACK= 2, FRONT=-2, ON=0
	int g,q;
	int x,y;

	//cout.setf(ios::fixed);
	//cout.precision(1); //小数点10桁表示
	cout <<;


	return EXIT_SUCCESS;
}
