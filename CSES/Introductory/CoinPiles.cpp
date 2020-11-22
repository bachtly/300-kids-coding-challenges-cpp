#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    
    while (t--) {
        int x, y;
        cin >>x >> y;
        
        if (x > y) swap(x,y);

        if (y <= 2*x && (2*x-y) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}