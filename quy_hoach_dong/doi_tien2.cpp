#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
#define MAX 10020202
void solve(){
	int n, x;
	cin >> n >> x;
	int c[n];
	for (int i = 0; i < n; i++)		cin >> c[i];
	int dp[x + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= x; i++){
		for (int j = 0; j < n; j++){
			if (i >= c[j]){
				dp[i] += dp[i - c[j]];
				dp[i] %= MOD;
			}
		}
	}
	cout << accumulate(dp, dp + x + 1, 0);

}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	tt = 1;
	while(tt--){
		solve();
		
	}
	return 0;
}