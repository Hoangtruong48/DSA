#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int MOD = 1e9 + 7;

void maximum_path_sum_1(long long* a, int n){
	long long res = LLONG_MIN, temp = 0;
	int start = 0, end = 0, s = 0;
	for (int i = 0; i < n; ++i){
		temp += a[i];
		if (res < temp){
			res = temp;
			start = s;
			end = i;
		}
		if (temp < 0){
			temp = 0;
			s = i + 1;
		}
	}
	cout << "maximum_path_sum = " << res << endl;
	cout << "starting index is " << start << endl;
	cout << "Ending index is " << end << endl;
}
long long crossSum(long long* a, int l, int m, int r){
	long long left = LLONG_MIN;
	long long sum = 0;
	for (int i = m; i >= l; i--){
		sum += a[i];
		if (sum > left){
			left = sum;
		}
	}
	sum = 0;
	long long right = LLONG_MIN;
	for (int i = m + 1; i <= r; i++){
		sum += a[i];
		if (sum > right){
			right = sum;
		}
	}
	return max({left, right, left + right});
}

long long maximum_path_sum_2(long long* a, int l, int r){
	if (l == r)
		return a[r];
	if (l > r)
		return LLONG_MIN;
	int m = (l + r) / 2;
	return max({maximum_path_sum_2(a, l, m), maximum_path_sum_2(a, m + 1, r), crossSum(a, l, m, r)});
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	long long Array[n];
	for (long long& x : Array)
		cin >> x;
	maximum_path_sum_1(Array, n);
	cout << maximum_path_sum_2(Array, 0, n - 1);
	

}