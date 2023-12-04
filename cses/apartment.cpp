#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



#define pb push_back
#define ll long long
#define endl "\n"
#define fi first
#define se second

const int MOD = 1e9 + 7;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	debug(k);
	int a[n];
	for (int i = 0; i < n; i++)	
		cin >> a[i];
	sort(a, a + n);
	multiset<int> b;
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		b.insert(x);
	}
	int cnt = 0;	
	for (int i = 0; i < n; i++){
		auto po = b.lower_bound(a[i] - k);
		auto po_ = b.upper_bound(a[i] + k);
		if (po != b.end() && *po <= a[i] + k){
			cnt += 1;
			debug(a[i], *po);
			b.erase(po);
		}
		else if (po == b.end() && po_ != b.end()){
			cnt += 1;
			debug(a[i], *po_);
			b.erase(po_);
		}
	}
	cout << cnt;
	return 0;
}