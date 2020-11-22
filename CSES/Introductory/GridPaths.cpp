#include<bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-parameter"

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());

const int N = 7;

string s;
bool c[N][N];
int result;
long long cnt = 0;

void DFS(int t, int x, int y) {
    cnt++;
    if (x == N-1 && y == 0) {
        if (t == 48) result++;
        return;
    }
    
    bool canNotMove = c[x][y];
    if (y > 0 && y < 6 && c[x][y - 1] == false && c[x][y + 1] == false &&
        ((x == 0 && c[x + 1][y] == true) || (x == 6 && c[x - 1][y] == true))) canNotMove = true;
    if (x > 0 && x < 6 && c[x - 1][y] == false && c[x + 1][y] == false &&
        ((y == 0 && c[x][y + 1] == true) || (y == 6 && c[x][y - 1] == true))) canNotMove = true;
    if (x > 0 && x < 6 && y > 0 && y < 6 && c[x - 1][y] == true &&
        c[x + 1][y] == true && c[x][y - 1] == false && c[x][y + 1] == false) canNotMove = true;
    if (x > 0 && x < 6 && y > 0 && y < 6 && c[x][y - 1] == true &&
        c[x][y + 1] == true && c[x - 1][y] == false && c[x + 1][y] == false) canNotMove = true;
    if (canNotMove) {
        return;
    }

    c[x][y] = true;

    if (s[t] != '?') {
        if (s[t] == 'L' && y > 0 && !c[x][y-1]) DFS(t+1, x, y-1);
        else if (s[t] == 'R' && y < N-1 && !c[x][y+1]) DFS(t+1, x, y+1);
        else if (s[t] == 'U' && x > 0 && !c[x-1][y]) DFS(t+1, x-1, y);
        else if (s[t] == 'D' && x < N-1 && !c[x+1][y]) DFS(t+1, x+1, y);
    }
    else {
        if (y > 0 && !c[x][y-1]) DFS(t+1, x, y-1);
        if (y < N-1 && !c[x][y+1]) DFS(t+1, x, y+1);
        if (x > 0 && !c[x-1][y]) DFS(t+1, x-1, y);
        if (x < N-1 && !c[x+1][y]) DFS(t+1, x+1, y);
    }

    c[x][y] = false;
}

int main() {

    // freopen("input.txt", "r", stdin);

    cin >> s;
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) c[i][j] = false;
    result = 0;
    DFS(0, 0, 0);

    cout << result << endl;
    // cout << cnt << endl;

    return 0;
}