#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;

int n, m;
int t[maxN];
multiset<int> h;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; ++i) cin >> t[i];

    for (int i = 0; i < m; ++i) {
        auto it = h.upper_bound(t[i]);
        if (it == h.begin()) cout << -1 << endl;
        else {
            cout << *(--it) << endl;
            h.erase(it);
        }
    }

    return 0;
}