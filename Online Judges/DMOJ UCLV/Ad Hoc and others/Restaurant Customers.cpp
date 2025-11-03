#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), s(n);

    for(int i=0;i<n;i++) cin >> a[i] >> s[i];
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());

    int l=0, r=0;
    int counter = 0;
    int maxx = 0;
    while(l<n && r<n) {
        if(a[l] < s[r]) {
            counter++;
            maxx = max(maxx, counter);
            l++;
        }
        else {
            counter--;
            r++;
        }
    }

    cout << maxx;
}