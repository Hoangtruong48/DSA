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

const int MOD = 1e9 + 7;

#define int long long

#define _Htruong48_ main()



void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)	cin >> x;
	int x = 0;
	for (int i = 0; i < n; i++){
		x++;
		if (x == a[i]){
			x++;
		}
		debug(i, x);
	}
	cout << x << endl;
}
_Htruong48_ {
	int tt; 	cin >> tt;
	while(tt--)	solve();
	int lens = 119;
	cout << __lg(119);
}