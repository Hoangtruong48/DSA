#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const int MOD = 1e9 + 7;
string S = "codeforces";

void solve(){
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); i++){
		if (s[i] != S[i]){
			cnt++;
		}
	}
	cout << cnt << endl;
}
auto main()->int{
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}