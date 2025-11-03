#include<bits/stdc++.h>
using namespace std;

const long long MOD = 100000007;

typedef long long ll;


struct matrix {
	ll mat[2][2];
	
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				c.mat[i][j] = 0;
				for(int k=0;k<2;k++) {
					c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
					c.mat[i][j] %= MOD;
				}
			}
		}
		return c;
	}
};

matrix matpow(matrix base, ll n) {
	matrix ans;
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) 
		    ans.mat[i][j] = (i == j);
	}
	while(n) {
		if(n&1) ans = ans * base;
		base = base * base;
		n >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	matrix base, ans;
	
	base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
	base.mat[1][1] = 0;
	
	while(n--) {
		int a; cin >> a;
		ans = matpow(base, a);
		
		cout << ans.mat[0][0] << " ";
		
	}
	
}