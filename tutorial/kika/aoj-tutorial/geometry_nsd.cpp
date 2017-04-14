// * geometry library

typedef double Real;
constexpr Real EPS = 1e-8;
const Real PI = acos((Real)-1);
inline int sign(Real d) { return d > EPS ? 1 : d < -EPS ? -1 : 0; }

struct point {
	Real x, y;
	explicit point():point(0, 0) {}
	explicit point(Real x_, Real y_):x(x_), y(y_) {}
	point operator+(const point &p) const { return point(x + p.x, y + p.y); }
	point operator-(const point &p) const { return point(x - p.x, y - p.y); }
	point operator*(const point &p) const { return point(x * p.x - y * p.y, x * p.y + y * p.x); }
	point operator*(Real s) const { return point(x * s, y * s); }
	point operator/(Real s) const { return point(x / s, y / s); }
	bool operator<(const point &p) const { return sign(x - p.x) == -1 || (sign(x - p.x) == 0 && sign(y - p.y) == -1); }
	bool operator>(const point &p) const { return sign(x - p.x) == 1 || (sign(x - p.x) == 0 && sign(y - p.y) == 1); }
	bool operator==(const point &p) const { return sign(x - p.x) == 0 && sign(y - p.y) == 0; }
	bool operator!=(const point &p) const { return sign(x - p.x) != 0 || sign(y - p.y) != 0; }
};

inline istream &operator>>(istream &is, point &p) {
	return is >> p.x >> p.y;
}

inline ostream &operator<<(ostream &os, const point &p) {
	return os << '(' << p.x << ", " << p.y << ')';
}

struct line : public array<point, 2> {
	line(const point &a, const point &b) { at(0) = a; at(1) = b; }
};

struct segment : public array<point, 2> {
	segment(const point &a, const point &b) { at(0) = a; at(1) = b; }
};

struct circle {
	point c;
	Real r;
	circle():c(point()), r(0) {}
	circle(const point &c_, Real r_):c(c_), r(r_) {}
};

typedef vector<point> polygon;

inline point rotate90(const point &p) {
	return point(-p.y, p.x);
}

inline point rotate(const point &p, Real theta) {
	const Real s = sin(theta), c = cos(theta);
	return point(c * p.x - s * p.y, s * p.x + c * p.y);
}

inline Real angle(const point &p) {
	return atan2(p.y, p.x);
}

inline Real norm(const point &p) {
	return p.x * p.x + p.y * p.y;
}

inline Real abs(const point &p) {
	return sqrt(norm(p));
}

inline Real dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}

inline Real cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

enum { CCW = 1, CW = -1, BACK = 2, FRONT = -2, ON = 0};
inline int ccw(const point &a, const point &b, const point &c) {
	const point p = b - a;
	const point q = c - a;
	const int sign_cross = sign(cross(p, q));
	if(sign_cross == 1) return CCW;
	if(sign_cross == -1) return CW;
	if(sign(dot(p, q)) == -1) return BACK;
	if(sign(norm(p) - norm(q)) == -1) return FRONT;
	return ON;
}

// 原点を始点とするベクトルa, b, cについて，
// cが「aからbへ反時計回りで回る角」の内部・辺上・外部のどこにあるか
// + : 内部
// 0 : 辺上 or A = B
// - : 外部
inline int judge(const point &a, const point &b, const point &c) {
	return sign(cross(a, c)) - sign(cross(b, c)) - sign(cross(a, b));
}

inline point project(const line &l, const point &p) {
	const point a = p - l[0];
	const point b = l[1] - l[0];
	return l[0] + b * (dot(a, b) / norm(b));
}

inline point reflect(const line &l, const point &p) {
	const point t = project(l, p);
	return t + (t - p);
}

inline bool intersect(const segment &s, const point &p) {
	return ccw(s[0], s[1], p) == ON;
}

inline bool intersect(const segment &a, const segment &b) {
	return ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]) <= 0
		&& ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]) <= 0;
}

inline bool intersect(const line &l, const point &p) {
	return abs(ccw(l[0], l[1], p)) != 1;
}

inline bool intersect(const line &l, const segment &s) {
	return sign(cross(l[1] - l[0], s[0] - l[0]) * cross(l[1] - l[0], s[1] - l[0])) <= 0;
}

inline bool intersect(const line &a, const line &b) {
	return sign(cross(a[1] - a[0], b[1] - b[0])) != 0 // not parallel
		|| sign(cross(a[1] - a[0], b[1] - a[0])) == 0; // same line
}

inline Real dist(const point &a, const point &b) {
	return abs(a - b);
}

inline Real dist(const line &l, const point &p) {
	const point a = l[1] - l[0];
	const point b = p - l[0];
	return abs(cross(a, b)) / abs(a);
}

inline Real dist(const line &l, const segment &s) {
	return intersect(l, s) ? 0 : min(dist(l, s[0]), dist(l, s[1]));
}

inline Real dist(const line &a, const line &b) {
	return intersect(a, b) ? 0 : dist(a, b[0]);
}

inline Real dist(const segment &s, const point &p) {
	if(sign(dot(s[1] - s[0], p - s[0])) == -1) return dist(s[0], p);
	if(sign(dot(s[0] - s[1], p - s[1])) == -1) return dist(s[1], p);
	return dist(line(s[0], s[1]), p);
}

inline Real dist(const segment &a, const segment &b) {
	return intersect(a, b) ? 0 : min({dist(a, b[0]), dist(a, b[1]), dist(b, a[0]), dist(b, a[1])});
}

inline bool intersect(const circle &a, const circle &b) {
	return sign(dist(a.c, b.c) - (a.r + b.r)) <= 0
		&& sign(dist(a.c, b.c) - abs(a.r - b.r)) >= 0;
}

inline bool intersect(const circle &c, const segment &s) {
	return sign(dist(s, c.c) - c.r) <= 0;
}

inline bool intersect(const circle &c, const line &l) {
	return sign(dist(l, c.c) - c.r) <= 0;
}

inline bool contain(const circle &c, const point &p) {
	return sign(dist(c.c, p) - c.r) <= 0;
}

inline bool contain(const polygon &P, const point &p) {
	bool res = false;
	for(int i = 0; i < P.size(); ++i) {
		point v1 = P[i] - p;
		point v2 = P[(i + 1) % P.size()] - p;
		if(v1.y > v2.y) swap(v1, v2);
		if(sign(cross(v1, v2)) == 0 && sign(dot(v1, v2)) <= 0) return true; // on edge
		if(sign(v1.y) <= 0 && sign(v2.y) == 1 && sign(cross(v1, v2)) == 1) res = !res;
	}
	return res;
}

// P is CCW
inline bool contain(const polygon &P, const segment &s) {
	const Real c = (EPS * 100);
	if(!contain(P, s[0] + (s[1] - s[0]) * c)) return false;
	if(!contain(P, s[1] + (s[0] - s[1]) * c)) return false;

	const int n = P.size();
	for(int i = 0; i < n; ++i) {
		const point &prev = P[(i - 1 + n) % n];
		const point &curr = P[i];
		const point &next = P[(i + 1) % n];

		if(ccw(curr, next, s[0]) * ccw(curr, next, s[1]) == -1
		   && ccw(s[0], s[1], curr) * ccw(s[0], s[1], next) == -1) return false;
		if(curr != s[0] && curr != s[1] && intersect(s, curr)) {
			if(judge(prev - curr, next - curr, s[0] - curr) > 0) return false;
			if(judge(prev - curr, next - curr, s[1] - curr) > 0) return false;
		}
	}

	return true;
}

inline bool contain_triangle(const polygon &triangle, const point &p) {
	const int d1 = ccw(p, triangle[0], triangle[1]);
	const int d2 = ccw(p, triangle[1], triangle[2]);
	const int d3 = ccw(p, triangle[2], triangle[0]);
	return !(d1 * d2 == -1 || d2 * d3 == -1 || d3 * d1 == -1);
}

inline bool contain_convex(const polygon &P, const point &g, const point &p) {
	const int n = P.size();
	int L = 0, R = n;
	while(L + 1 < R) {
		const int M = (L + R) / 2;
		if(judge(P[L] - g, P[M] - g, p - g) >= 0) {
			R = M;
		}
		else {
			L = M;
		}
	}
	return contain_triangle({g, P[L], P[(L + 1) % n]}, p);
}

inline point crosspoint(const line &a, const line &b) {
	assert(intersect(a, b));
	const Real crs = cross(a[1] - a[0], b[1] - b[0]);
	if(sign(crs) == 0) return a[0]; // same line
	return b[0] + (b[1] - b[0]) * (cross(a[1] - a[0], a[1] - b[0]) / crs);
}

inline point crosspoint(const segment &a, const segment &b) {
	assert(intersect(a, b));
	const Real crs = cross(a[1] - a[0], b[1] - b[0]);
	if(sign(crs) == 0) { // on same line
		if(intersect(a, b[0])) return b[0];
		if(intersect(a, b[1])) return b[1];
		if(intersect(b, a[0])) return a[0];
		return a[1];
	}
	return b[0] + (b[1] - b[0]) * (cross(a[1] - a[0], a[1] - b[0]) / crs);
}

inline vector<point> crosspoint(const circle &c, const line &l) {
	const point p = project(l, c.c);
	const Real h = dist(p, c.c);
	vector<point> res;
	if(sign(h - c.r) == 1) {
		// nothing
	}
	else if(sign(h - c.r) == 0) {
		res.emplace_back(p);
	}
	else {
		const Real b = sqrt(c.r * c.r - h * h);
		const point e = (l[1] - l[0]) / abs(l[1] - l[0]);
		res.emplace_back(p + e * b);
		res.emplace_back(p - e * b);
	}
	return res;
}

inline vector<point> crosspoint(const circle &c, const segment &s) {
	vector<point> res;
	for(const point &p : crosspoint(c, line(s[0], s[1]))) {
		if(intersect(s, p)) res.emplace_back(p);
	}
	return res;
}

inline vector<point> crosspoint(const circle &a, const circle &b) {
	if(!intersect(a, b)) return vector<point>();
	vector<point> res;
	const point v = b.c - a.c;
	const Real d = abs(v);
	if(sign(d - (a.r + b.r)) == 0) {
		res.emplace_back(a.c + (v * (a.r / d)));
	}
	else {
		const Real r_cos = (d * d + a.r * a.r - b.r * b.r) / (d + d);
		const Real r_sin = sqrt(a.r * a.r - r_cos * r_cos);
		const point e = v / d;
		res.emplace_back(a.c + e * point(r_cos, r_sin));
		res.emplace_back(a.c + e * point(r_cos, -r_sin));
	}
	return res;
}

inline Real area(const polygon &P) {
	Real res = 0;
	for(int i = 0; i < P.size(); ++i) {
		res += cross(P[i], P[(i + 1) % P.size()]);
	}
	return abs(res) * 0.5;
}

inline Real rad(point a, point b, const point &base = point(0, 0)) {
	a = a - base;
	b = b - base;
	const int c = ccw(point(0, 0), a, b);
	return abs(c) != 1 ? 0 : c * acos(dot(a, b) / (abs(a) * abs(b)));
}

inline Real common_area(const circle &a, const circle &b) {
	if(!intersect(a, b)) return (contain(a, b.c) || contain(b, a.c) ? min<Real>(a.r * a.r, b.r * b.r) * PI : 0);
	const point &p = crosspoint(a, b).front();
	return a.r * a.r * abs(rad(p, b.c, a.c)) + b.r * b.r * abs(rad(p, a.c, b.c)) - abs(cross(a.c - p, b.c - p));
}

inline Real common_area(circle c, point a, point b) {
	a = a - c.c;
	b = b - c.c;
	c.c = c.c - c.c;

	const vector<point> cp = crosspoint(c, line(a, b));
	if(cp.size() == 0) return c.r * c.r * rad(a, b) / 2;

	const bool b1 = sign(abs(a) - c.r) == 1;
	const bool b2 = sign(abs(b) - c.r) == 1;
	const point &p = cp.front();
	const point &q = cp.back();

	if(b1 && b2) {
		if(sign(dot(a - p, b - p)) <= 0 && sign(dot(a - q, b - q)) <= 0) {
			return (c.r * c.r * (rad(a, b) - rad(p, q)) + cross(p, q)) / 2;
		}
		else {
			return c.r * c.r * rad(a, b) / 2;
		}
	}
	else if(b1) {
		return (c.r * c.r * rad(a, p) + cross(p, b)) / 2;
	}
	else if(b2) {
		return (c.r * c.r * rad(q, b) + cross(a, q)) / 2;
	}
	else {
		return cross(a, b) / 2;
	}
}

inline Real common_area(const polygon &P, const circle &c) {
	Real res = 0.0;
	for(int i = 0; i < P.size(); ++i) {
		res += common_area(c, P[i], P[(i + 1) % P.size()]);
	}
	return abs(res);
}

// l[0]からl[1]の方向を見た場合に，点aが左側に来る．
inline line bisector(const point &a, const point &b) {
	return line(point((a.x - a.y + b.x + b.y) * 0.5, (a.y + a.x + b.y - b.x) * 0.5),
				point((a.x + a.y + b.x - b.y) * 0.5, (a.y - a.x + b.y + b.x) * 0.5));
}

inline polygon convex_hull(vector<point> points) {
	const int n = points.size();
	if(n <= 3) return points;

	sort(begin(points), end(points));
	int k = 0;
	polygon res;
	res.resize(2 * n);
	for(int i = 0; i < n; res[k++] = points[i++]) {
		while(k >= 2 && ccw(res[k - 2], res[k - 1], points[i]) <= 0) --k;
	}

	const int t = k + 1;
	for(int i = n - 2; i >= 0; res[k++] = points[i--]) {
		while(k >= t && ccw(res[k - 2], res[k - 1], points[i]) <= 0) --k;
	}
	res.resize(k - 1);
	return res;
}

// l[0]からl[1]を向いた時の左側を残して切断する．
inline polygon convex_cut(const polygon &P, const line &l) {
	polygon res;
	for(int i = 0; i < P.size(); ++i) {
		const point &curr = P[i];
		const point &next = P[(i + 1) % P.size()];
		const int curr_ccw = ccw(l[0], l[1], curr);
		const int next_ccw = ccw(l[0], l[1], next);
		if(curr_ccw != -1) res.emplace_back(curr);
		if(curr_ccw * next_ccw < 0) res.emplace_back(crosspoint(l, line(curr, next)));
	}
	return res;
}

inline vector<point> tangent(const circle &c, const point &p) {
	const point v = p - c.c;
	const Real x = norm(v);
	const Real d = x - c.r * c.r;
	const int sgn = sign(d);
	if(sgn == -1) return {};
	if(sgn == 0) return {p};
	const point q1 = v * (c.r * c.r / x);
	const point q2 = rotate90(v * (c.r * sqrt(d) / x));
	return {c.c + q1 - q2, c.c + q1 + q2};
}

inline vector<line> tangent(const circle &a, const circle &b) {
	vector<line> res;
	const point v = b.c - a.c;
	const Real d = abs(v);
	if(sign(d) <= 0) return res;

	const auto make_tangent = [&](const point &p) {
		const vector<point> ps = tangent(a, p), qs = tangent(b, p);
		for(int i = 0; i < min(ps.size(), qs.size()); ++i) res.emplace_back(ps[i], qs[i]);
	};

	const Real dif_r = b.r - a.r;
	const Real sum_r = a.r + b.r;

	// 外接線が2種類存在
	if(sign(d - abs(dif_r)) == 1) {
		if(sign(dif_r) == 0) {
			const point v2 = rotate90(v * (a.r / d));
			res.emplace_back(a.c + v2, b.c + v2);
			res.emplace_back(a.c - v2, b.c - v2);
		}
		else {
			make_tangent(a.c + v * (-a.r / dif_r));
		}
	}

	// 内接線が2種類存在
	if(sign(d - sum_r) == 1) {
		make_tangent(a.c + v * (a.r / sum_r));
	}

	// 接点が2円の円周上にあるような接線が存在
	if(sign(d - abs(dif_r)) == 0 || sign(d - sum_r) == 0) {
		const point p = a.c + v * (a.r / d);
		res.emplace_back(p, p + rotate90(v));
	}
	return res;
}

inline void merge(vector<segment> &segments) {
	for(int i = 0; i < segments.size(); ) {
		const segment &s1 = segments[i];
		bool ok = true;
		for(int j = i + 1; j < segments.size(); ++j) {
			const segment &s2 = segments[j];

			if(intersect(s1, s2) && sign(cross(s1[0] - s1[1], s2[0] - s2[1])) == 0) {
				const point a = min({s1[0], s1[1], s2[0], s2[1]});
				const point b = max({s1[0], s1[1], s2[0], s2[1]});
				segments.emplace_back(a, b);
				segments.erase(segments.begin() + j);
				segments.erase(segments.begin() + i);
				ok = false;
				break;
			}
		}
		if(ok) ++i;
	}
}

struct edge {
	int to;
	Real cost, theta;
	bool used;
	edge(int to_, Real cost_, Real theta_):to(to_), cost(cost_), theta(theta_), used(false) {}
	bool operator<(const edge &e) const { return theta < e.theta; }
};

typedef vector<vector<edge>> graph;
graph arrangement(vector<segment> &segments, vector<point> &points) {
	merge(segments);
	const int n = segments.size();
	points.clear();

	for(int i = 0; i < n; ++i) {
		const segment &s1 = segments[i];
		points.emplace_back(s1[0]);
		points.emplace_back(s1[1]);

		for(int j = i + 1; j < n; ++j) {
			const segment &s2 = segments[j];
			if(intersect(s1, s2)) points.emplace_back(crosspoint(s1, s2));
		}
	}

	sort(begin(points), end(points));
	points.erase(unique(begin(points), end(points)), end(points));

	const int V = points.size();
	graph G(V);
	for(const segment &s : segments) {
		vector<pair<Real, int>> vs;
		for(int i = 0; i < V; ++i) {
			if(intersect(s, points[i])) vs.emplace_back(abs(s[0] - points[i]), i);
		}

		sort(begin(vs), end(vs));
		for(int i = 1; i < vs.size(); ++i) {
			const int v = vs[i].second;
			const int u = vs[i - 1].second;
			const Real d = vs[i].first - vs[i - 1].first;
			G[v].emplace_back(u, d, angle(points[u] - points[v]));
			G[u].emplace_back(v, d, angle(points[v] - points[u]));
		}
	}
	for(vector<edge> &edges : G) sort(begin(edges), end(edges));
	return G;
}

vector<polygon> find_faces(graph &G, const vector<point> &points) {
	vector<polygon> res; // 符号付き面積が正なら外側

	const int V = G.size();
	for(int i = 0; i < V; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			int v = i;
			int e_idx = j;
			polygon P;

			while(true) {
				edge &e = G[v][e_idx];
				if(e.used) break;

				e.used = true;
				P.emplace_back(points[v]);
				for(int k = 0; k < G[e.to].size(); ++k) {
					if(G[e.to][k].to == v) {
						v = e.to;
						e_idx = (k + 1) % G[e.to].size();
						break;
					}
				}
			}
			if(P.size() >= 3) res.emplace_back(move(P));
		}
	}
	return res;
}
