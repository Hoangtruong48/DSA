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
	int n, m;
	cin >> n >> m;
	multiset<int> price;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		price.insert(x);
	}
	int a[m];
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		auto position = price.lower_bound(a[i]);
		debug(*position, a[i], price);
		if (price.size() == 0){
			cout << -1;
		}
		else if (a[i] < *price.begin()){
			cout << -1;
		}
		else if (*position == a[i]){
			cout << a[i];
			price.erase(position);
		} else {
			if (position == price.end()){
				auto k = price.cend();
				k--;
				if (a[i] > *(k)){
					cout << *(k);
					price.erase(k);
				}
			} else {
				--position;
				cout << *position;
				price.erase(position);
			}
		}

		cout << endl;
	}

	return 0;
}