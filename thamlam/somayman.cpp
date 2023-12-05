#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
long long a[1000];

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 177; i++){
		if (n == a[i]){
			cout << "CO";
			return;
		}
	}
	cout << "KHONG";


}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	for (int i = 1; i <= 178; i++){
		a[i] = 1ll * i * i * i * i;
	}
	int tt;
	cin >> tt;
	while(tt--){
		solve();
		cout << "\n";
	}

}