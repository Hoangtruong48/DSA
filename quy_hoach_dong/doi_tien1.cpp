#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
#define MAX 10020202
void solve(){
	int n; cin >> n;
	int S; cin >> S;
	int c[n];
	for (int i = 0; i < n; i++)	cin >> c[i];
	int dp[S + 1];
	for (int i = 0; i <= S; i++)	dp[i] = MAX;
	dp[0] = 0;
	for (int i = 1; i <= S; i++){
		for (int j = 0; j < n; j++){
			if (i >= c[j]){
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}
	}
	if (dp[S] != MAX)
		cout << dp[S];
	else{
		cout << -1;
	}


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