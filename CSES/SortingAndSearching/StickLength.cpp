#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int n;
long long p[maxN];
long long pre[maxN], post[maxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p, p+n);

    pre[0] = p[0];
    for (int i = 1; i < n; ++i) pre[i] = pre[i-1] + p[i];
    post[n-1] = p[n-1];
    for (int i = n-2; i >= 0; --i) post[i] = post[i+1] + p[i];

    long long result = min(pre[n-1] - n*p[0], n*p[n-1] - post[0]);
    for (int i = 1; i < n-1; ++i) {
        long long val = (i*p[i] - pre[i-1]) + (post[i+1] - (n-i-1)*p[i]);
        result = min(result, val);
    }

    cout << result << endl;

    return 0;
}