#include<bits/stdc++.h>

#define int long long

using namespace std;

main() {
    int l = 1;
    int r = 2 * long(1e9);
    string op = "";

    while(l <= r) {

        int mid = (l+r) / 2;
        cout << mid << '\n';
        cin >> op;

        if(op == ">") {
            r = mid - 1;
        }
        else if(op == "<") {
            l = mid + 1;
        }
        else break;
    }

    fflush(stdout);
}