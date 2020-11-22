#include <bits/stdc++.h>
using namespace std;

void preprocessing(set<char> &s, int *arr, string &str) {
    for (int i = 'a'; i <= 'z'; ++i) arr[i] = 0;
    for (char i : str) {
        arr[i]++;
        s.insert(i);
    }
}

void backtrack(set<string> &s2, set<char> &s1, int *arr, string accum, int maxPos) {
    if (accum.size() == maxPos) {
        if (s2.find(accum) == s2.end()) s2.insert(accum);
        return ;
    }
    for (char i : s1) {
        if (arr[i] <= 0) continue;
        arr[i]--;
        backtrack(s2, s1, arr, accum+char(i), maxPos);
        arr[i]++;
    }
}

int main() {

    set<string> s2;
    set<char> s1;
    int arr[150];
    
    string str;
    cin >> str;

    preprocessing(s1, arr, str);

    backtrack(s2, s1, arr, "", str.size());

    cout << s2.size() << endl;
    for (string i : s2) cout << i << endl;

    return 0;
}