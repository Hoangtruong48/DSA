#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
#define MAX 10010101
int dp[1002020];
int main(){
	int n, s;
	cin >> n >> s;
	for (int i = 0; i <= s; i++)
		dp[i] = MAX;
	int v[n];
	for (int &x : v)
		cin >> x;
	dp[0] = 0;
	for (int i = 1; i <= s; i++){
		for (int j = 0; j < n; j++){
			if (i >= v[j]){
				dp[i] = min(dp[i], dp[i - v[j]] + 1);
			}
		}
	}
	
}