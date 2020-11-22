#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>
#define ll long long

const int maxN = 2e5+1;
ll n, accum;
int a[maxN];

void preprocess() {
    cin >> n;
    accum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        accum += 1LL * a[i];
    }
    sort(a, a+n);
}

void sol() {
    cout << max( 2LL*a[n-1], accum) << endl;
}

int main() {

    preprocess();
    sol();

    return 0;
}