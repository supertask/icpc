#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<list>
#define reps(i,p,n) for(int i=p;i<(int)(n);i++)
#define rep(i,n) reps(i,0,n)
#define all(c) (c).begin(), (c).end()
using namespace std;
list<bool*> mul_disjoints;
int n,q;

bool* find_point(int point) {
	for (list<bool*>::iterator it = mul_disjoints.begin(); it != mul_disjoints.end(); it++ ) {
		bool *is_numbers = *it;
		if(is_numbers[point]) { return is_numbers; }
	}
	return NULL;
}

void copy_right_to_left(bool *left, bool *right) {
	rep(i,n) {
		left[i] = (left[i] || right[i]);
	}
	return;
}

int main() {
	int is_same,x,y;
	
	cin >> n >> q;
	rep(i,q) {
		cin >> is_same >> x >> y; //in(is_same,x,y)
		if (is_same) {
			bool is_number = false;
			for (list<bool*>::iterator it = mul_disjoints.begin(); it != mul_disjoints.end(); it++ ) {
				bool *is_numbers = *it;
				if (is_numbers[x] && is_numbers[y]) {
					is_number = true;
				}
			}
			cout << is_number << endl;

		}
		else { //unit
			if(mul_disjoints.empty()) {
				bool is_numbers[10000] = {false};
				is_numbers[x] = true;
				is_numbers[y] = true;
				mul_disjoints.push_back(is_numbers);
			}
			else {
				bool is_find_number = false;
				for (list<bool*>::iterator it = mul_disjoints.begin(); it != mul_disjoints.end(); it++ ) {
					bool *is_left_numbers = *it;
					if (is_left_numbers[x]) { 
						is_find_number = true;
						bool *is_right_numbers = find_point(y);
						if (is_right_numbers == NULL) {
							is_left_numbers[y] = true;	
						}
						else {
							copy_right_to_left(is_left_numbers,is_right_numbers);
							mul_disjoints.remove(is_right_numbers);
						}
					}
					else if (is_left_numbers[y]) { 
						is_find_number = true;	
						bool *is_right_numbers = find_point(x);
						if (is_right_numbers == NULL) {
							is_left_numbers[x] = true;	
						}
						else {
							copy_right_to_left(is_left_numbers,is_right_numbers);
							mul_disjoints.remove(is_right_numbers);
						}
					}
				}
				if (! is_find_number) {
					bool is_left_numbers[10000] = {false};
					is_left_numbers[x] = true;	
					is_left_numbers[y] = true;	
					mul_disjoints.push_back(is_left_numbers);
				}
			}
		}
		/*
		cout << "-----" << endl;
		for (list<bool*>::iterator it = mul_disjoints.begin(); it != mul_disjoints.end(); it++ ) {
			bool *is_numbers = *it;
			rep(j,n) {
				cout << is_numbers[j];
			}
			cout << " ";
		}
		cout << endl;
		cout << "-----" << endl;
		*/
	}

	return 0;
}
