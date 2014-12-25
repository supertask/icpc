#include <iostream>
#include <algorithm>
using namespace std;

const int coin[6] = {6,5,4,3,2,1};

int solve(int a)
{
    if (a == 0) {
        return 0;
	}

    for (int i = 0; i < 6; ++i) {
        if (a >= coin[i]) {
            return solve(a - coin[i]) + 1;
		}
	}

    return -1;
}

int main()
{
    int a;
    cin >> a;

    int ans = solve(a);
    cout << ans << endl;
}
