#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

long long t(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll tmp = t(a, b / 2);
	if (b % 2 == 0){
		return (tmp % MOD * tmp % MOD) % MOD;
	}
	else{
		return ((a % MOD * tmp % MOD) % MOD * tmp % MOD) % MOD;
	}
}

bool check1(long long n)
{
	int r = n % 10;
	int l = 0;
	while (n != 0){
		l = n % 10;
		n /= 10;
	}
	if (r == 2 * l || l == 2 * r)
		return true;
	return false;
}

bool check2(long long n)
{
	int dem = 0;
	while (n != 0){
		dem++;
		n /= 10;
	}
	long long csdau = n / pow(10, dem);
	n /= 10;
	n -= csdau * pow(10, dem - 1);
	long long temp = n, a = 0;
	while (temp != 0){
		a = a * 10 + temp % 10;
		temp /= 10;
	}
	if (a == n)
		return true;
	return false;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[30][30], b[30][30], c[30][30];
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= n; j++){
    		cin >> a[i][j];
    	}
    }
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= n; j++){
    		cin >> b[i][j];
    	}
    }
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= n; j++){
    		c[i][j] = 0;
    	}
    }
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= n; j++){
    		int tt = 0;
    		for (int k = 0; k <= n; k++){
    			tt += a[i][k] * b[k][j];
    		}
    		c[i][j] = tt;
    	}
    }
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= n; j++){
    		cout << c[i][j] << " ";
    	}
    	cout << endl;
    }

    
}