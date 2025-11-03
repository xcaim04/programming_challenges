#include <bits/stdc++.h>
#define int long long
#define float long double
#define endl "\n"
#define pb push_back()

using namespace std;

int const nmax = 1e7;
int dp[nmax] , sol;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n , num;  cin>>n;

    for(int i=0 ; i<n ; i++){
        cin>>num;
        sol += ( ( (i+1)-dp[num] ) * ( (n-(i+1))+1 ) );
        dp[num] = (i+1);
    }
    
    cout<<sol;

    return 0;
}