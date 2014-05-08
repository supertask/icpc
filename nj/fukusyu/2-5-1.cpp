#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#include<ctime>
#include<cstring>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_    str(),re); tok != NULL; tok = strtok(NULL,re))
#define all(c) (c).begin(), (c).end()
using namespace std;

bool bsearch(vector<int> values,int C) {
	int first = 0;
	int last = values.size();
	int middle;
	while (first + 1 < last) {
		middle = (first+last)/2;
		if (values[first] < values[middle]) {
			last = ;
		}
		else {
			middle = first;
		}
	}
	return
}

int main() {
	int N,C;
	int value;
	vector<int> values;

	scanf("%d %d", &N, &C);
	rep(i,N) {
		scanf("%d", &value);
		values.push_back(value);
	}
	sort(all(values));
	bsearch(values,C);

	return 0;
}
