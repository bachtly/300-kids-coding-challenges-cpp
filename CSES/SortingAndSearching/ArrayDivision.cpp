#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll oo = 1e17;

int main() {

    int n, k;
    cin >> n >> k;

    ll L = 0, R = 0;

    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        R += a[i];
        L = max(L, a[i]);
    }
    L = max(L, R/n);


    ll result = oo;
    while (L <= R) {
        ll mid = (L+R) >> 1;

        ll x = 1;
        ll i, localRes = mid;

        for (i = 1; i <= k; ++i) {
            ll cnt = 0;
            while (cnt+a[x] <= mid && x<=n) cnt += a[x++];
            localRes = max(localRes, cnt);
        }

        if (i<=k || x>n) {
            result = min(result, localRes);
            R = mid-1;
        }
        else L = mid+1;
    }

    cout << result << endl;

    return 0;
}