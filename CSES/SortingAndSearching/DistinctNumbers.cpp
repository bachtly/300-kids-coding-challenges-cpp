#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int n;

int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    cout << a.size() << endl;

    return 0;
}