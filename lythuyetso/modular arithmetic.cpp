#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
const int  MOD =  int(1e9+7);

int res(int n, int m, int c)
{
	int r = 1;
	for (int i = 1; i <= m; i++){
		r *= n;
		r %= c;
	}
	return r;
}
int legendre(ll n, int m)
{
	ll res = 0;
	for (ll i = m; i <= n; i *= m){
		res += long(n / i);
	}
	return res;
}

long long pow1(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll tmp = pow1(a, b / 2);
	if (b % 2 == 0)
		return tmp * tmp;
	else return tmp * tmp * a;
}
// O( log 2(b) )

long long pow11(ll a, ll b, ll c)
{
	if (b == 0)
		return a;
	ll tmp = pow11(a, b / 2, c);
	if (b % 2 == 0)
		return (tmp % c) * (tmp % c) % c;
	else
		return (((tmp % c) * (tmp % c) % c) * (a % c)) % c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    long long n;
    int p;
    cin >> n >> p;
    cout << legendre(n, p) << endl;
    cout << pow11(2, 1e18, 10);
}	