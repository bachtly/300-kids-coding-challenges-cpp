#include <bits/stdc++.h>
using namespace std;

#define ll long long

// void print_set(set<int> &s) {
//     for (int i : s) cout << i << endl;
// }

ll get_sum(int *a, int n) {
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += (ll) a[i];
    }
    return result;
}

void preprocessing(int* &a, int n) {
    a = new int[n];
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> a[i];
    }
    sort(a, a+n);
}

void backtrack(int *a, int n, set<ll> &result, ll crt_sum) {
    for (int i = 0; i < n; ++i) {
        result.insert((ll)crt_sum+a[i]);
        backtrack(a+i+1, n-i-1, result, (ll)crt_sum+a[i]);
    }
}

int main() {

    int n;
    cin >> n;

    int *a;

    preprocessing(a, n);

    set <ll> result; 
    backtrack(a, n, result, 0);

    ll sumA = get_sum(a, n);
    ll res = 9999999999999;
    // cout << "RESULT" << endl;
    for (ll i : result) {
        // cout << i << endl;
        res =  min(res, abs(sumA-2*i));
    }
    cout << res << endl;


    return 0;
}