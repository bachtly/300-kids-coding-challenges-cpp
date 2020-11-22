#include <bits/stdc++.h>
using namespace std;

const int oo = 2e9;
#define i2 pair<int,int>

int main() {
    int n;
    cin >> n;

    vector<i2> a;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(i2(tmp, i+1));
    }

    stack<i2> stk;
    stk.push(i2(-oo, 0));
    for (int i = 0; i < n; ++i) {
        int val = a[i].first;
        while (!stk.empty() && a[i].first <= stk.top().first) {
            stk.pop();
        }
        cout << stk.top().second << " ";
        stk.push(a[i]);
    }

    return 0;
}