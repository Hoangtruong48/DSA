#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

//int dp[1001][1002];
void solve()
{
	string a, b, c;
	cin >> a >> b >> c;
	int sz_a = (int)a.size(), sz_b = (int)b.size(), sz_c = (int)c.size();
	int dp[sz_a + 1][sz_b + 1][sz_c + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= sz_a; i++){
		for (int j = 1; j <= sz_b; j++){
			for (int k = 1; k <= sz_c; k++){
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]){
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else{
					dp[i][j][k] = max({dp[i - 1][j - 1][k], dp[i][j - 1][k - 1], dp[i - 1][j][k - 1],
						dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
				}
			}
		}
	}
	cout << dp[sz_a][sz_b][sz_c];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}