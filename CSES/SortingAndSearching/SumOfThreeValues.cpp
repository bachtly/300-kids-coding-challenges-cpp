#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>
#define ll long long

const int maxN = 5e3+1;
ll n, x;
i2 a[maxN];

void preprocess() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a + n);
}

void sol() {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            auto it = lower_bound(a+j+1, a+n, i2(x - a[i].first - a[j].first, 1));
            if (it != a+n && it->first + a[i].first + a[j].first == x) {
                cout << a[i].second << " " << a[j].second << " " << it->second << endl;
                return ;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {

    preprocess();
    sol();

    return 0;
}