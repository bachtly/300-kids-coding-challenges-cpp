#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>
#define ll long long

const int maxN = 5e3+1;
ll n, x;
int a[maxN];

void preprocess() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void sol() {
    map<int, bool> hasSum;
    for (int i = 0; i < n; ++i) {
        if (i>1) {
            for (int j = i+1; j < n; ++j) {
                if (a[i] + a[j] < x) {
                    if (hasSum[x - a[i] - a[j]]) {
                        for (int t = 0; t < i; ++t) {
                            for (int k = t+1; k < i; ++k) {
                                if (a[t] + a[k] + a[i] + a[j] == x) {
                                    cout << t+1 << " " << k+1 << " " << i+1 << " " << j+1 << endl;\
                                    return;
                                } 
                            }
                        }
                    }
                }
            } 
        }
        
        for (int j = 0; j < i; ++j) {
            if (a[i] + a[j] < x) hasSum[a[i] + a[j]] = true;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {

    preprocess();
    sol();

    return 0;
}