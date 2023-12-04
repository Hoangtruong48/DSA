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
	int n;
	cin >> n;
	long long sum = 1ll * n * (n + 1) / 2;
	if (sum % 2 == 0 && n > 1){
		cout << "YES" << endl;
		long long res = sum / 2;
		vector<int> set1;
		vector<int> set2;
		for (int i = n; i > 0; i--){
			if (res - i >= 0){
				set1.push_back(i);
				res -= i;
			} else {
				set2.push_back(i);
			}
		}
		cout << (int)set1.size() << endl;
		for (int x : set1){
			cout << x << " ";
		}
		cout << endl;
		cout << (int)set2.size() << endl;
		for (int x : set2){
			cout << x << ' ';
		}
	} else {
		cout << "NO";
	}
	return 0;
}