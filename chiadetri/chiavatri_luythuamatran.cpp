#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int MOD = 1e9 + 7;

struct matrix
{
	ll a[2][2];
	matrix operator * (matrix b){
		matrix res;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				res.a[i][j] = 0;
				for (int k = 0; k < 2; k++){
					res.a[i][j] +=  a[i][k] * b.a[k][j];
					res.a[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};

matrix powMod(matrix a, long long n){
	if (n == 1)
		return a;
	matrix temp = powMod(a, n / 2);
	if (n % 2 == 0){
		return temp * temp;
	}
	else{
		return a * temp * temp;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	cin >> n;
	matrix tmp;
	tmp.a[0][0] = 1;
	tmp.a[0][1] = 1;
	tmp.a[1][0] = 1;
	tmp.a[1][1] = 0;
	matrix res = powMod(tmp, n);
	cout << res.a[0][1];
}