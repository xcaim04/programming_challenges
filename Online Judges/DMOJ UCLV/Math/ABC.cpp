#include<iostream>
using namespace std;

int n,res=0;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;i*j<=n;j++){
            res+=n/(i*j);
        }
    }
    cout<<res;
}