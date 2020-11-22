#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;

    int result = 1, tmp = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[i-1]) tmp++;
        else tmp = 1;
        result = max(result, tmp);
    }
    cout << result << endl;

    return 0;
}