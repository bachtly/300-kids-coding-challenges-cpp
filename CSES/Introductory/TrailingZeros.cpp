#include <bits/stdc++.h>
using namespace std;

int log5(int n) {
    return log(n)/log(5);
}

int main() {

    int n;
    cin >> n;

    int result = 0;
    int acum = 5;
    
    for (int i = 1; i <= log5(n); ++i) {
        result += n/acum;
        acum*=5;
    }
    cout << result << endl;

    return 0;
}