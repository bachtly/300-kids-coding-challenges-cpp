#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i]%n;
        a[i] = (a[i] + n) %n;
    }
    
    vector<long long> pref(n+1);
    pref[0] = 0;
    for (int i = 1; i<= n; ++i) pref[i] = (pref[i-1] + a[i])%n;
    
    set<long long> s;
    map<long long,long long> m;
    long long result = 0;

    s.insert(0);
    m[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long tmp = pref[i];
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