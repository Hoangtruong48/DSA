#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = a[1][1];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = a[i][j] + max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
		}
	}
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n][m];

	return 0;
}