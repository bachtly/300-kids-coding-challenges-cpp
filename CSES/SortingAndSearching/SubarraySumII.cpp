#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    vector<long long> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i<= n; ++i) pref[i] = pref[i-1] + a[i];
    
    set<long long> s;
    map<long long,long long> m;
    long long result = 0;

    s.insert(0);
    m[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long tmp = -x + pref[i];
        if (s.find(tmp) != s.end()) {
            result += m[tmp];
        }
        if (s.find(pref[i]) == s.end()) {
            s.insert(pref[i]);
            m[pref[i]] = 1;
        } 
        else m[pref[i]]++;
    }

    cout << result << endl;

    return 0;
}