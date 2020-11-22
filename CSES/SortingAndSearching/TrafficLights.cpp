#include<bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>

int x, n;
set<i2> d;
multiset<int> len;

void preprocess() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> n;
    d.insert(i2(x, 0));
    len.insert(x);
}

int main() {

    preprocess();

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;

        auto it = d.lower_bound({p, 0});
        int L = it->second;
        int R = it->first;

        d.erase(it);
        len.erase(len.find(R-L));

        d.insert({p, L});
        len.insert({p-L});
        d.insert({R, p});
        len.insert({R-p});

        cout << *(len.rbegin()) << " ";
    }

    return 0;
}