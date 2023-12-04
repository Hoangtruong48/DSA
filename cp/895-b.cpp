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

#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

std::pair<int, int> find(int l, int r) {
    int a = (l % 2 != 0) ? l : l + 1;
    while (a <= r) {
        if (isPrime(a)) {
            int b = a + 2;
            if (b <= r && isPrime(b))
                return std::make_pair(a, b);
        }
        a += 2;
    }
    return std::make_pair(-1, -1);  // Trả về giá trị không hợp lệ nếu không tìm thấy
}

void solve(){
	int l, r;
	cin >> l >> r;
	pair<int, int> res = find(l, r);
	if (res.fi == - 1){
		cout << -1;
	} else {
		cout << res.fi << " " << res.se;
	}
	cout << endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
	return 0;
}