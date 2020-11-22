#include <bits/stdc++.h>
using namespace std;

int n, x;
const int maxN = 2e5 + 1;
int a[maxN], b[maxN];

void sol(int t1, int t2) {
    int p1, p2;
    for (int i = 0; i < n; ++i) {
        if (b[i] == t1) {
            p1 = i+1;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == t2 && i+1 != p1) p2 = i+1;
    }
    cout << p1 << " " << p2 << endl;
}

int main() {

    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(a, a+n, x-a[i]);
        if (it == a+n-1 || it == a+i || *it+a[i] != x) continue;
        sol(a[i], *it);
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}