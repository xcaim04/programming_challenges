#include <bits/stdc++.h>

using namespace std;

int arr[6001],dp[6001][6001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j]=dp[i][j-1];
            if(arr[i]<arr[j]) dp[i][j]++;
        }
        for(int j=1;j<i;j++) dp[i][j]+=dp[i-1][j];
    }
    int q; cin>>q;
    while(q--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        cout<<dp[d][b]-dp[d][a-1]-dp[c-1][b]+dp[c-1][a-1]<<"\n";
    }


    return 0;
}