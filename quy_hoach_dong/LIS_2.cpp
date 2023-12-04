#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> res;
	//res.push_back(a[0]);
	for (int i = 0; i < n; i++){
		auto lower = lower_bound(res.begin(), res.end(), a[i]);
		if (lower == res.end()){
			res.push_back(a[i]);
		}
		else{
			auto iter = lower - res.begin();
			//cout << iter << endl;
			*(res.begin() + iter) = a[i];
		}
	}
	cout << (int)res.size();
	return 0;
}