#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
const int MAX = 22929225;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = (int)s.size();
	//cout << n << endl;
	pair<int, int> res;
	bool dp[n + 1][n + 1];
	memset(dp, false, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	int ans = -112323;
	for (int lens = 2; lens <= n; lens++){
		for (int i = 0; i <= n - lens; i++){
			int j = i + lens - 1;
			if (lens == 2 && s[i] == s[j]){
					dp[i][j] = true;
			}
			else{
				dp[i][j] = ((s[i] == s[j] && dp[i + 1][j - 1]) ? true : false);
			}
			if (dp[i][j]){
				ans = max(ans, lens);
				res = make_pair(i, j);
			}
		}
		
	}
	cout << ans << endl;
	//cout << res.first << " " << res.second << endl;
}