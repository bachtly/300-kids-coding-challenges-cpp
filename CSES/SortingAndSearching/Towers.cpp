#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> towers;

int main() {

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;

        auto it = upper_bound(towers.begin(), towers.end(), tmp);
        if (it == towers.end()) towers.push_back(tmp);
        else *it = tmp;
    }
    cout << towers.size() << endl;

    return 0;
}