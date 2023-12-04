#include <bits/stdc++.h>

using namespace std;
long long fibo[93];
char solve(int n, long long k){
	if (n == 1)
		return 'A';
	if (n == 2)
		return 'B';
	if (k <= fibo[n - 2]){
		return solve(n - 2, k);
	}
	else{
		return solve(n - 1, k - fibo[n - 2]);
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long long n, k;
	cin >> n >> k;
	
	fibo[1] = 1, fibo[2] = 1;
	for (int i = 3; i <= 92; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << solve(n, k);

	

}