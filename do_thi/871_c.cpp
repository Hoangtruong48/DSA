#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int time1 = 2000000, time2 = 2000000;
	vector<int> res;
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		//cin.ignore(1);
		string s;
		cin >> s;
		if (s[0] == '1' && s[1] == '1'){
			res.push_back(m);
		}
		else{
			if (s[0] == '1'){
				time1 = min(time1, m);
			}
			if (s[1] == '1'){
				time2 = min(time2, m);
			}
		}
	}
	int ans = time1 + time2;
	for (int i = 0; i < (int)res.size(); i++){
		ans = min(ans, res[i]);
	}
	if (ans > 2000000){
		cout << -1;
	}
	else
		cout << ans;
	cout << endl;
}
auto main()->int{
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}