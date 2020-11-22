#include <bits/stdc++.h>
using namespace std;

const int num = 1e9+7;

long long two_exp(int n) {
    if (n==1) return 2;
    long long t = two_exp(n/2)%num;
    if (n%2==0) return t*t%num;
    else return 2*t*t%num;
}

int main() {

    int n;
    cin >> n;

    cout << two_exp(n) << endl;

    return 0;
}