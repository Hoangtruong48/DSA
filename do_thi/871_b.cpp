#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	int res = -1;
	int a[n];
	for (int& x : a)
		cin >> x;
	for (int i = 0; i < n; i++){
		if (a[i] == 0){
			cnt++;
		}
		else{
			res = max(res, cnt);
			cnt = 0;
		}
	}
	res = max(res, cnt);
	cout << res << endl;
}
auto main()->int{
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}