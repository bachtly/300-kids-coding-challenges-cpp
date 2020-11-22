#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k; 
    cin >> n >> k;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> tmpVec{0};
    for (int i = 1; i <= k; ++i) tmpVec.push_back(a[i]);
    sort(tmpVec.begin(), tmpVec.end());

    multiset<int, greater<int> > sml;
    multiset<int> grt;
    for (int i = 1; i <= (k+1)/2; ++i) sml.insert(tmpVec[i]);
    for (int i = (k+1)/2 + 1; i <= k; ++i) grt.insert(tmpVec[i]);

    // cout << "CHECKING" << endl;
    // for (int i : sml) cout << i << " ";
    // cout << endl;
    // for (int i : grt) cout << i << " ";
    // cout << endl;

    int result = *sml.begin();
    cout << result << " ";
    for (int i = 2; i <= n-k+1; ++i) {
        if (a[i-1] > result) grt.erase(grt.find(a[i-1]));
        else sml.erase(sml.find(a[i-1]));
        if (a[i+k-1] > result) grt.insert(a[i+k-1]);
        else sml.insert(a[i+k-1]);
        
        // cout << "CHECKing" << sml.size() - grt.size() << endl;
        if (sml.size() > grt.size() + 1) {
            grt.insert(*sml.begin());
            sml.erase(sml.begin());
        }
        else if (sml.size() < grt.size()) {
            sml.insert(*grt.begin());
            grt.erase(grt.begin());
        }

        result = *sml.begin();
        cout << result << " ";
    } 

    return 0;
}