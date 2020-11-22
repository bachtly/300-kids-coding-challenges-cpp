#include <bits/stdc++.h>
using namespace std;

string s[8];
int result;

void recursion(int a[8], int cnt) {
    if (cnt == 8) {
        result++;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        if (s[cnt][i] == '*') continue;
        bool flag = true;
        for (int j = 0; j < cnt; ++j) {
            if (i == a[j] || abs(i-a[j]) == cnt - j) flag = false;
        }
        if (flag) {
            a[cnt] = i;
            recursion(a, cnt+1);
        }
    }
}

int main() {

    for (int i = 0; i < 8; ++i) cin >> s[i];
    result = 0;

    int a[] = {0,0,0,0,0,0,0,0};
    recursion(a, 0);
    cout << result << endl;

    return 0;
}