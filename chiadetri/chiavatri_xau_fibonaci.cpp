#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int MOD = 1e9 + 7;
long long fibo[94];
void init(){
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= 92; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
}
char solve(int n, long long k){
	if (n == 1)
		return 'A';
	if (n == 2){
		return 'B';
	}
	if (k > fibo[n - 2]){
		return	solve(n - 1, k - fibo[n - 2]);
	}
	else{
		return solve(n - 2, k);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	long long k;
	cin >> n >> k;
	init();
	cout << solve(n , k) << endl;
}