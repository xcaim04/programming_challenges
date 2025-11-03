#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    multiset<int> t;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        t.insert(a);
    }
    for(int j=0;j<m;j++) {
        int a;
        cin >> a;
        auto pos = t.upper_bound(a);
        if(pos != t.begin()) {
            cout << *(--pos) << "\n";
            t.erase(pos);
        }
        else cout << -1 << "\n";
    }
}