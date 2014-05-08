#include <iostream>
#include <algorithm>
using namespace std;

bool bsearch(int A[], int AL[], int value)
{
	int first = 0;
	int last = AL-A;
    while (first + 1 < last) {
        int middle = (first+last) / 2;
        if (value < A[middle]) {
			last = middle;
		}
        else {
			first = middle;
		}
    }
    return first < last && A[first] == value;
}

int main()
{
	int SL,TL;
	cin >> SL;
    int S[SL];
	for(int i = 0; i < SL; i++) {
        cin >> S[i];
    }
	
	cin >> TL;
	int T[TL];
    for(int i = 0; i < TL; i++) {
        cin >> T[i];
    }
	
    sort(S,S+SL);
	
	int count=0;
    for(int i = 0; i < TL; i++) {
		if (bsearch(S,S+SL,T[i])) {
			count++;
		}
		/* if (binary_search(S, S+SL, T[i])) {
		 count++;
		 } */
    }
    cout << count << endl;
	
    return 0;
}

