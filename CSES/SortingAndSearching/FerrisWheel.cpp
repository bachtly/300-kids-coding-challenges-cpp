#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;

int n, x, result, accum;
int p[maxN];

void preprocess() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) accum += p[i];
    sort(p, p+n, greater<int>());
    accum = 0;
}

bool sol(int k) {
    priority_queue<int, vector<int>, greater<int> > Q;
    for (int i = 0; i < k; ++i) Q.push(p[i]);
    for (int i = k; i < n; ++i) {
        if (Q.top() + p[i] > x) return false;
        Q.push(Q.top() + p[i]);
        Q.pop();
    }
    result = k;
    return true;
}

int main() {

    preprocess();

    int l = max(accum/x + 1, (n+1)/2),
        r = n;

    result = r;
    while (l <= r) {
        int mid = (l+r)/2;
        // cout << l << " " << r << " " << mid << endl;
        if (sol(mid)) r = mid-1;
        else l = mid+1;
    }
    cout << result << endl;

    return 0;
}