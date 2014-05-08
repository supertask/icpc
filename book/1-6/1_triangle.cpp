#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    /*
     * 4*3*2*1 = 4!
     */
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                cout << "何回" << endl;
                int arroundLen = a[i]+a[j]+a[k];
                int maxLen = max(a[i], max(a[j], a[k]));
                int otherLen = arroundLen - maxLen;
                if (otherLen > maxLen) {
                    ans = max(ans, arroundLen);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}