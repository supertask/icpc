/*
// BEGIN CUT HERE
// PROBLEM STATEMENT
// Computers tend to store dates and times as single numbers which represent the number of seconds or milliseconds since a particular date.  Your task in this problem is to write a method whatTime, which takes an int, seconds, representing the number of seconds since midnight on some day, and returns a string formatted as "<H>:<M>:<S>".  Here, <H> represents the number of complete hours since midnight, <M> represents the number of complete minutes since the last complete hour ended, and <S> represents the number of seconds since the last complete minute ended.  Each of <H>, <M>, and <S> should be an integer, with no extra leading 0's.  Thus, if seconds is 0, you should return "0:0:0", while if seconds is 3661, you should return "1:1:1".

DEFINITION
Class:Time
Method:whatTime
Parameters:int
Returns:string
Method signature:string whatTime(int seconds)


CONSTRAINTS
-seconds will be between 0 and 24*60*60 - 1 = 86399, inclusive.


EXAMPLES

0)
0

Returns: "0:0:0"

1)
3661

Returns: "1:1:1"

2)
5436

Returns: "1:30:36"

3)
86399

Returns: "23:59:59"

// END CUT HERE
*/
#line 43 "Time.cc"

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<climits>
#include<ctime>
#include<cstring>
#include<sstream>
#define REP(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))
#define ALL(c) (c).begin(), (c).end()
#define dump(a) cerr << #a << "=" << (a) << endl
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //t=min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //t=max
using namespace std;

int main() {

	return 0;
}
