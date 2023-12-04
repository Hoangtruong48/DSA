#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

set<int> se;
void init(int k){
	if (k % 3 == 0 && k != 0){
		int temp1 = k / 3 * 2;
		int temp2 = k / 3;
		if (se.find(temp1) == se.end()){
			se.insert(temp1);
			init(temp1);
		}
		if (se.find(temp2) == se.end()){
			se.insert(temp2);
			init(temp2);
		}
	}
	else{
		return;
	}
}
const int MOD = 1e9 + 7;
void solve(){
	se.clear();
	int n, m;
	cin >> n >> m;
	int temp1 = -1, temp2 = -1;
	if (n == m){
		cout << "YES" << endl;
		return;
	}
	se.insert(n);
	//bool c = false;
	//set<int> se;
	if (n % 3 != 0){
		cout << "NO" << endl;
		return;
	}
	temp1 = n / 3 * 2;
	temp2 = n / 3;
	se.insert(temp1);
	se.insert(temp2);
	init(temp1);
	init(temp2);
	// for (int x : se){
	// 	cout << x << " ";
	// }
	if (se.find(m) != se.end()){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	cout << endl;
}
auto main()->int{
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}