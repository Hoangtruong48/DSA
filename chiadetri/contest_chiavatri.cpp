#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
const int MOD = 1e9 + 7;

vector<int> v;

void init(ll n){
	int tmp = log2(n);
	for (int i = 0; i <= tmp; i++)
		v.push_back((int)pow(2, i));
}

int find(ll pos, ll n, int index){
	if (pos % 2 == 1)
		return 1;
	if (pos == v[index])
		return n % 2;
	else if (pos < v[index]){
		return find(pos, n / 2, index - 1);
	}
	else{
		return find(2 * v[index] - pos, n / 2, index - 1);
	}
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, l, r;
    cin >> n >> l >> r;
    ll ans = 0;
    init(n);
    int m = (int)v.size() - 1;
    for (ll i = l; i <= r; i++){
    	ans += find(i, n, m);
    }
    cout << ans;
    return 0;

}