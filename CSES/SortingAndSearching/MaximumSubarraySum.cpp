#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
int n;
int a[maxN];

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    queue<int> Q;
    long long accum = 0;

    long long result = -999999999;
    for (int i = 0; i < n; ++i) result = max(result, (long long)a[i]);

    for (int i = 0; i < n; ++i) {
        Q.push(a[i]);
        accum += (long long) a[i];

        while (accum < 0 && !Q.empty()) {
            accum -= Q.front();
            Q.pop();
        }
        if (!Q.empty()) result = max(result, accum);
    }

    cout << result << endl;

    return 0;
}