#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (x).size()

int main()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    int n;
    cin >> n;

    //Despues de aplicar algebra se obtiene la expresion
    // (n-1)(a^2 + b^2 + ... + z^2) - 2[a(b+c+...+z) + b(c+d+...+z) + ... + y*z]
    //      Factor 1 f1                Factor 2     f2
    
    ll ans = 0;
    ll f1 = 0, f2 = 0;

    vector<ll>pf (n + 1, 0);//Guarda la suma a + b + c + ... + z
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        f1 += x * x;
        pf[i] = pf[i - 1] + x;
    }

    //Hallar f2
    for (int i = 1; i < n; ++i)
    {
        ll x = pf[i] - pf[i - 1];
        f2 += x * (pf[n] - pf[i]);
    }

    ans = (n - 1ll) * f1 - 2ll * f2;
    cout << ans;

    return 0;
}
