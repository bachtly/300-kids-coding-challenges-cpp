#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    vector<long long> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i<= n; ++i) pref[i] = pref[i-1] + a[i];
 
    int t1 = 0, t2 = 1;
    int result = 0;
    while (t1 <= t2 && t2 <= n) {
        long long val = pref[t2] - pref[t1];
        if (val == x) result++;
        if (val >= x) t1++;
        else t2++;
    }   

    cout << result << endl;     

    return 0;
}