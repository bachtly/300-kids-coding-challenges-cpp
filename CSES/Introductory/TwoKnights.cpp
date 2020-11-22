#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        if (i!=1) {
            result = (long long) i*i*(i*i-1)/2 - 4*(i-1)*(i-2);
        }
        cout << result << endl;
    }


    return 0;
}