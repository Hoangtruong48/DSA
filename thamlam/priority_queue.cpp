#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
int dd[1000005];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> q;
	int k;
	cin >> k;
	cin.ignore(1);
	string s;
	cin >> s;
	map<char, int> mp1;
	for (char x : s)
		mp1[x]++;
	for (auto x : mp1){
		q.push(x.second);
	}
	for (int i = 0; i < k; i++){
		int a = q.top();
		q.pop();
		q.push(max(a - 1, 0));
	}
	long long ans = 0;
	while((int)q.size() > 0){
		int a = q.top();
		ans += (ll)a * a;
		q.pop();
	}
	cout << ans;
	return 0;
}