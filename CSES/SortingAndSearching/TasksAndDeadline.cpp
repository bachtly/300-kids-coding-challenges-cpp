#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>
#define ll long long

int n;
vector<i2> a;
ll result;

void preprocess() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back(i2(x, y));
    }
    sort(a.begin(), a.end());
}

void sol() {
    for (int i = 0; i < n; ++i) {
        result += (ll) a[i].second;
        result -= (ll) a[i].first*(n-i);
    }
    cout << result << endl;
}

int main() {

    preprocess();
    sol();

    return 0;
}