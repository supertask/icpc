#include<iostream>
using namespace std;

int main() {
    int L,n;
    cin >> L;
	cin >> n;
	
    int x[n];
	int mini = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i];
		mini = max(mini, min(x[i], L - x[i]));
    }
	
	int maxi = 0;
	for (int i=0; i<n; i++) {
		maxi = max(maxi, max(x[i], L - x[i]));
    }
	cout << mini << " " << maxi << endl;
    return 0;
}