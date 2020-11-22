#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    bool *check = new bool[n+1];

    for (int i = 1; i <= n; ++i) check[i] = false;
    int tmp;
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        check[tmp] = true;
    }

    for (int i = 1; i <= n; ++i) 
        if (check[i] == false) cout << i << endl;

    return 0;
}