#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
const int MAX = 22929225;
int dp[2002022];
int main(){
	int n, S;
	cin >> n >> S;
	int a[n];
	for (int &x : a)
		cin >> x;
	for (int i = 0; i <= S; i++){
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= S; j++){
			if (j >= a[i]){
				dp[j] += dp[j - a[i]];
				dp[j] %= MOD;
			}
		}
	}
	cout << dp[S];
}