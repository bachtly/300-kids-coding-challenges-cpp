#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    long long result = 0;
    int crt = 0, tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < crt) result += (long long) crt - tmp;
        crt = max(crt, tmp);
    }
    cout << result << endl;

    return 0;
}