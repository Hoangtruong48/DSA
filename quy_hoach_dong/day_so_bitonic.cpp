#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
const int MAX = 22929225;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)		cin >> a[i];
	vector<int> res1(n, 0), res2(n, 0);
	res1[0] = a[0];
	for (int i = 1; i < n; i++){
		res1[i] = a[i];
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]){
				res1[i] = max(res1[i], res1[j] + a[i]);
			}
		}
	}
	res2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--){
		res2[i] = a[i];
		for (int j = n - 1; j > i; j--){
			if (a[i] > a[j]){
				res2[i] = max(res2[i], res2[j] + a[i]);
			}
		}
	}
	int ans = -12121;
	for (int i = 0; i < n; i++){
		ans = max(ans, res1[i] + res2[i] - a[i]);
	}
	cout << ans;

	return 0;
}