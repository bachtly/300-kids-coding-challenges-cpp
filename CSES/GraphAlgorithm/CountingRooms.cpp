#include <bits/stdc++.h>
using namespace std;

#define pairii pair<int,int>
#define x first
#define y second


void BFS(string* &s, int i, int j, int n, int m) {
    set<pairii> seti{pairii(0,1), pairii(0,-1), pairii(1,0), pairii(-1,0)};
    queue <pairii > Q;
    s[i][j] = '#';
    Q.push(pairii(i, j));

    while (!Q.empty()) {
        pairii p = Q.front();
        Q.pop();


        for (pairii t : seti) {
            if ((p.x+t.x)*(p.x+t.x-n+1)>0 || (p.y+t.y)*(p.y+t.y-m+1)>0) continue;
            if (s[p.x+t.x][p.y+t.y] == '.') {
                s[p.x+t.x][p.y+t.y] = '#';
                Q.push(pairii(p.x+t.x, p.y+t.y));
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    string *s = new string[n];

    for (int i = 0; i < n; ++i) cin >> s[i];
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                BFS(s, i, j, n, m);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}