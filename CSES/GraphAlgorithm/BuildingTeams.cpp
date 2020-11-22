#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;

int n, m, tag[maxN+1];
vector <int> adj[maxN+1];
bool visited[maxN];


void preprocessing() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool BFS(int t) {
    queue<int> Q;
    Q.push(t);
    tag[t] = 1;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int p : adj[u]) {
            if (!visited[p]) {
                visited[p] = true;
                tag[p] = 3 - tag[u];
                Q.push(p);
            }
            else if (tag[u] == tag[p]) return false;
        }
    }
    return true;
}

int main() {

    preprocessing();

    for (int i = 0; i <= n; ++i) visited[i] = false;

    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) 
            if (!BFS(i)) flag = false;
    }

    if (!flag) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 1; i <= n; ++i) {
            cout << tag[i];
            if (i != n) cout << " ";
        }
        cout << endl;
    }

    return 0;
}