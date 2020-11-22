#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;

int n, m, k;
int a[maxN], b[maxN];

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a, a+n, greater<int>());
    sort(b, b+m, greater<int>());

    int h_a = 0, h_b = 0;
    int result = 0;
    while (h_a < n && h_b < m) {
        if (b[h_b] > a[h_a]+k) h_b++;
        else if (b[h_b] < a[h_a]-k) h_a++;
        else {
            h_a++; 
            h_b++; 
            result++;
        }
    }

    cout << result << endl;

    return 0;
}