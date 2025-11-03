#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long maxx = INT_MIN;
    long long sum = 0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        sum += a;
        if(sum > maxx) {
            maxx = sum;
        }

        if(sum < 0) sum = 0;
    }

    cout << maxx;
}