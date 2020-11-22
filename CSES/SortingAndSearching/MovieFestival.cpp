#include<bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>

int n;
vector<i2> a;
vector<int> a_sub;

void preprocess() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y; 
        cin >> x >> y;

        a.push_back(i2(x,y));
        a_sub.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(a_sub.begin(), a_sub.end());
}

int main() {

    preprocess();
    
    int *b = new int[n+1];
    b[n-1] = 1;
    for (int i = n-2; i >= 0; --i) {
        int val1, val2;

        auto it = lower_bound(a_sub.begin(), a_sub.end(), a[i].second);
        if (it == a_sub.end()) val1 = 1;
        else val1 = 1 + b[it-a_sub.begin()]; 

        val2 = b[i+1];

        b[i] = max(val1, val2);
    }
    cout << b[0] << endl;

    return 0;
}