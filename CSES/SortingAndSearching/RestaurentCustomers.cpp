#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>

int main() {

    int n;
    cin >> n;

    vector<i2> a;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back(i2(x, y));
    }

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<int> > Q;

    int result = 1;
    for (int i = 0; i < n; ++i) {
        while (Q.size() > 0 && Q.top() <= a[i].first) Q.pop();
        Q.push(a[i].second);
        result = max(result,(int) Q.size());
    }
    cout << result << endl;
 
    return 0;
}