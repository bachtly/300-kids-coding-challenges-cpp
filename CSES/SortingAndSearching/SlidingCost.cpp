#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, k; 
    cin >> n >> k;

    vector<long long> a(n+1);
    for (long long i = 1; i <= n; ++i) cin >> a[i];

    vector<long long> tmpVec{0};
    for (long long i = 1; i <= k; ++i) tmpVec.push_back(a[i]);
    sort(tmpVec.begin(), tmpVec.end());

    multiset<long long, greater<long long> > sml;
    multiset<long long> grt;
    long long a_sml = 0, a_grt = 0;
    for (long long i = 1; i <= (k+1)/2; ++i) {
        sml.insert(tmpVec[i]);
        a_sml += tmpVec[i];
    }
    for (long long i = (k+1)/2 + 1; i <= k; ++i) {
        grt.insert(tmpVec[i]);
        a_grt += tmpVec[i];
    }

    long long result = *sml.begin();
    long long t1 = result*sml.size()-a_sml + a_grt-result*grt.size();
    long long tmp = *sml.begin();
    if (!grt.empty()) tmp = *grt.begin();
    long long t2 = tmp*sml.size()-a_sml + a_grt-tmp*grt.size();
    if (t1 < t2) cout << t1 << " ";
    else cout << t2 << " ";

    for (long long i = 2; i <= n-k+1; ++i) {
        if (a[i-1] > result) {
            grt.erase(grt.find(a[i-1]));
            a_grt -= a[i-1];
        }
        else {
            sml.erase(sml.find(a[i-1]));
            a_sml -= a[i-1];
        }

        if (a[i+k-1] > result) {
            grt.insert(a[i+k-1]);
            a_grt += a[i+k-1];
        }
        else {
            sml.insert(a[i+k-1]);
            a_sml += a[i+k-1];
        }
        
        if (sml.size() > grt.size() + 1) {
            grt.insert(*sml.begin());
            a_grt += *sml.begin();
            a_sml -= *sml.begin();
            sml.erase(sml.begin());
        }
        else if (sml.size() < grt.size()) {
            sml.insert(*grt.begin());
            a_sml += *grt.begin();
            a_grt -= *grt.begin();
            grt.erase(grt.begin());
        }

        result = *sml.begin();
        long long t1 = result*sml.size()-a_sml + a_grt-result*grt.size();
        long long tmp = *sml.begin();
        if (!grt.empty()) tmp = *grt.begin();
        long long t2 = tmp*sml.size()-a_sml + a_grt-tmp*grt.size();
        if (t1 < t2) cout << t1 << " ";
        else cout << t2 << " ";
    } 

    return 0;
}