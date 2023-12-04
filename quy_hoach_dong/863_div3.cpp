#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;

int main(){
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<int> b(n - 1);
		for (int& x : b)
			cin >> x;
		for (int i = 0; i < n; i++){
			if (i == 0){
				cout << b[0];
			}
			else if (i == n - 1){
				cout << b[n - 2];
			}
			else{
				cout << min(b[i - 1], b[i]);
			}
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}