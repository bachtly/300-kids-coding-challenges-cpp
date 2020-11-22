#include <bits/stdc++.h>
using namespace std;

#define pairii pair<int,int>
#define x first
#define y second 

void BFS(string* &s, string* &f, int i, int j, int m, int n) {
    queue<pairii > Q;
    Q.push(pairii(i, j));
    set <pairii> seti {pairii(1,0), pairii(-1,0), pairii(0,1), pairii(0,-1)};

    while (!Q.empty()) {
        pairii p = Q.front();
        Q.pop();

        for (pairii t : seti) {
            if ( (p.x+t.x)*(p.x+t.x-m+1)>0 || (p.y+t.y)*(p.y+t.y-n+1)>0 ) continue;
            if ( s[p.x+t.x][p.y+t.y] == 'B') {
                if (t.x == -1) f[p.x+t.x][p.y+t.y] = 'U';
                else if (t.x == 1) f[p.x+t.x][p.y+t.y] = 'D';
                else if (t.y == 1) f[p.x+t.x][p.y+t.y] = 'R';
                else if (t.y == -1) f[p.x+t.x][p.y+t.y] = 'L';
                cout << "YES" << endl;
                
                //NOOOOOOOO
                for (int i = 0; i < m;++i) cout << f[i] << endl;\

                return;


                string presult = "";
                int a = p.x+t.x, b = p.y + t.y;
                int cnt = 1;
                while (s[a][b] != 'A') {
                    presult += f[a][b];
                    if (f[a][b] == 'U') a += 1;
                    else if (f[a][b] == 'D') a -= 1;
                    else if (f[a][b] == 'R') b -= 1;
                    else if (f[a][b] == 'L') b += 1;
                    cnt++;
                }

                string result = "";
                for (int i = presult.size()-1; i >= 0; --i) result += presult[i];
                cout << cnt << endl;
                cout << result << endl;

                return ;    
            }
            if ( s[p.x+t.x][p.y+t.y] == '.') {
                s[p.x+t.x][p.y+t.y] == '#';
                Q.push(pairii(p.x+t.x, p.y+t.y));
                if (t.x == -1) f[p.x+t.x][p.y+t.y] = 'L';
                else if (t.x == 1) f[p.x+t.x][p.y+t.y] = 'D';
                else if (t.y == 1) f[p.x+t.x][p.y+t.y] = 'R';
                else if (t.y == -1) f[p.x+t.x][p.y+t.y] = 'L';
            }
        }

    }

    cout << "NO" << endl;
}

int main() {

    int m, n;
    cin >> m >> n;

    string *s = new string[m], 
           *funstring = new string[m];
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        funstring[i] = s[i];
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'A') {
                BFS(s, funstring, i, j, m, n);
                return 0;
            }
        }

    return 0;
}