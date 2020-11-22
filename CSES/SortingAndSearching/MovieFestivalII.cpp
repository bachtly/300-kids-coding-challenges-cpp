//NOT COMPLETE
#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int, int>
#define x first
#define y second

vector<i2> t;
multiset<i2> min_heap;
vector<i2> a;

bool comp(i2 a, i2 b) {
    return a.y > b.y;
}

int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int t1, t2; 
        cin >> t1 >> t2;
        a.push_back(i2(t1,t2));
    }
    sort(a.begin(), a.end());

    min_heap.insert(i2(a[0].y, 0));
    t.push_back(i2(a[0].y, 1));
    for (int i = 1; i < n; ++i) {
        if (a[i].x < (*min_heap.begin()).x) {
            t.push_back(i2(a[i].y, 1));
            min_heap.insert(i2(a[i].y, t.size()-1));
        }
        else {
            i2 u  = *min_heap.begin();
            min_heap.erase(min_heap.find(i2(t[u.y].x, u.y)));
            t[u.y].x = a[i].y; t[u.y].y++;
            min_heap.insert(i2(a[i].y, u.y));
        }
    }

    cout << "PRINT A" << endl;
    for (i2 p : a) cout << p.x << " = " << p.y << endl ;
    cout << "PRINT T" << endl;
    for (i2 p : t) cout << p.x << " - " << p.y << endl;

    sort(t.begin(), t.end(), comp);
    int result = 0;
    for (int i = 0; i < k; ++i) result += t[i].y;
    cout << result << endl;

    return 0;
}