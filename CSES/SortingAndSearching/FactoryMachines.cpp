#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> machines;
long long l = 1e9, r = 1e18;

long long min(long long a, long long b) {
    if (a<b) return a;
    else return b;
} 

void preprocess() {
    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        machines.push_back(tmp);
        l = min(tmp, l);
    }
}

long long work(long long time, int t) {
    long long res = 0;
    for (int machine : machines) {
        res += time/machine;
        if (res >= t) return res;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preprocess();

    long long result = r;
    while (l <= r) {
        long long mid = (l+r)/2;
        long long prods = work(mid, t);
        if (prods < t) l = mid+1;
        else {
            r = mid-1;
            result = min(result, mid);
        }
    }
    cout << result << endl;

    return 0;
}