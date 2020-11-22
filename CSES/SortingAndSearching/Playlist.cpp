#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int n;
int k[maxN];

int main() {

    set<int> s;
    queue<int> Q;

    cin >> n;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int tmpSize = s.size();
        int tmp;
        cin >> tmp;

        s.insert(tmp);
        Q.push(tmp);
        if (s.size() == tmpSize) {
            while (Q.front() != tmp) {
                s.erase(Q.front());
                Q.pop();
            }
            Q.pop();
        }

        result = max(result,(int) Q.size());
    }

    cout << result << endl;

    return 0;   
}