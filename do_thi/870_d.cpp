#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for (int& x : a)	cin >> x;
	int l = 0, r = n - 1;
	int res = 0;
	while(l < r){
		res = __gcd(res,abs(a[l] - a[r]));
		l++;
		r--;
	}
	cout << res << endl;
}
auto main()->int{
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}