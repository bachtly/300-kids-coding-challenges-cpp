#include <bits/stdc++.h>
using namespace std;

int main () {

    int t; 
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int ma = max(x, y);
        int mi = min(x, y);

        long long result;

        if (x < y)
            if (ma%2 == 1) result = (long long) ma*ma+1 - mi;
            else result = (long long) (ma-1)*(ma-1) + mi;
        else 
            if (ma%2 == 0) result = (long long) ma*ma+1 - mi;
            else result = (long long) (ma-1)*(ma-1) + mi;
        cout << result << endl;
    }

    return 0;
}