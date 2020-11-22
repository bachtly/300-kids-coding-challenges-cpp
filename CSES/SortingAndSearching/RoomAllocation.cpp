#include<bits/stdc++.h>
using namespace std;

class i2 {
public:
    int first, second, pos;
    i2(int first, int second, int pos) {
        this->first = first;
        this->second = second;
        this->pos = pos;
    }
    i2() {
        i2(0,0,0);
    }
};

class Comp {
public:
    bool operator() (const i2& a, const i2& b) {
        return a.first > b.first;
    }
};

int n;
vector<i2> c;
priority_queue<i2, vector<i2>, Comp> Q;

void sync() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool comp(i2 a, i2 b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool comp2(i2 a, i2 b) {
    return a.pos < b.pos;
}

void preprocess() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        c.push_back(i2(x, y, i+1));
    }
    sort(c.begin(), c.end(), comp);
}

int main() {

    sync();
    preprocess();

    vector<i2> result;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (Q.empty() || Q.top().first >= c[i].first) {
            Q.push(i2(c[i].second, ++cnt, 0));
            result.push_back(i2(cnt, 0, c[i].pos));
        }
        else {
            Q.push(i2(c[i].second, Q.top().second, 0));
            result.push_back(i2(Q.top().second, 0, c[i].pos));
            Q.pop();
        }
    }
    cout << Q.size() << endl;
    sort(result.begin(), result.end(), comp2);
    for (i2 i : result) cout << i.first << " ";

    return 0;
}