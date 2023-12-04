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


const int MOD = 1e9 + 7;

using vi = vector<int>; 
                     
     
void solve() 
{ 
    int n;   
    cin >> n;
    vi arr(n);                  
    for (int i = 0; i < n; i++) 
        cin >> arr[i]; 

    if (n % 2 == 0) 
    { 
        cout << 2 << endl; 
        cout << 1 << ' ' << n << endl; 
        cout << 1 << ' ' << n << endl; 
    } 
    else 
    { 
        cout << 4 << endl; 
        cout << 1 << ' ' << n << endl; 
        cout << 1 << ' ' << n - 1 << endl; 
        cout << n - 1 << ' ' << n << endl; 
        cout << n - 1 << ' ' << n << endl; 
    } 
} 
 
signed main() 
{ 
    int tt;
    cin >> tt;
    while(tt--) 
        solve(); 
    return 0; 
}