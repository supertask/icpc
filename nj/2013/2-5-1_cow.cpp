#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool check(int X[], int middle, int N, int C)
{
    int count = 1;
    int lastBasyo = X[0];

    for (int i = 1; i < N; i++) {
        if (X[i] - lastBasyo >= middle) {
            count++;
            lastBasyo = X[i];
        }
    }
    if (count >= C) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
	int N,C;
	scanf("%d %d", &N, &C);

    int X[N];
    for (int i = 0; i < N; i++) {
        scanf("%d",X+i);
    }
    
    sort(X,X+N);
    
    int first = 0, last = 1000000001;
    while (first + 1 < last) {
        int middle = (first+last) / 2;
        if (check(X,middle,N,C)) {
            first = middle;
        }
        else {
            last = middle;
        }
    }
    cout << first << endl;
    
    return 0;
}



