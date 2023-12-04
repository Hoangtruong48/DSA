#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	char a[n + 1][n + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (a[i][j] == '.'){
				dp[i][j] = 1 + max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
			}
			else{
				dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	cout << dp[n][n];
}