#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define MAX 28382382

const int MOD = 1e9 + 7;

int main(){
	string s;
	cin >> s;
	int n = (int)s.size();
	long long dp[n + 1][n + 1];
	for (int i = 1; i <= n; i++){
		dp[i][i] = (int)(s[i - 1] - '0');
		//cout << dp[i][i] << endl;	
	}
	for (int i = 1; i <= n - 1; i++){
		for (int j = i + 1; j <= n; j++){
			dp[i][j] = dp[i][j - 1] * 10 + int(s[j - 1] - '0');
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (i <= j){
				res += dp[i][j];
			}
		}
	}
	cout << res;
}