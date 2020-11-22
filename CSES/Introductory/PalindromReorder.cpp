#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;

    // cout << str.size() << endl;

    int arr[100];
    for (int i = 0; i < 100; ++i) arr[i] = 0;

    for (char i : str) arr[i]++;

    int flag = 1;
    for (int i = 'A'; i <= 'Z'; ++i) 
        if (arr[i]%2==1) {
            if (str.size()%2 == 1 && flag == 1) flag = 0;
            else {
                flag = -1; 
                break;
            }
        } 

    if (flag == -1) cout << "NO SOLUTION" << endl;
    else {
        string result = str;
        int cnt = 0;
        char charLater = '-';
        
        for (int i = 'A'; i <= 'Z'; ++i) {
            if (arr[i]%2 == 1) {
                charLater = char(i);
                continue;
            }
            for (int j = 0; j < arr[i]/2; ++j) {
                result[cnt] = char(i);
                result[str.size()-1-cnt] = char(i);
                cnt++;
            }
        }

        if (charLater != '-') {
            for (int j = 0; j < arr[int(charLater)]/2; ++j) {
                result[cnt] = charLater;
                result[str.size()-1-cnt] = charLater;
                cnt++;
            }
            result[cnt] = charLater;
        } 

        cout << result << endl;
    }

    return 0;
}