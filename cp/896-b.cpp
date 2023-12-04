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
  int tt; cin >> tt; 
  while(tt--){ 
    long long n, k, a, b; cin >> n >> k >> a >> b; 
    long long ra, sa, rb, sb; 
    long long sola = 2e18, solb = 2e18; 
    pair<long long,long long> pairs[n]; 
     
    for(int i = 1; i <= n; i++){ 
      long long x,y; cin >> x >> y; 
      pairs[i-1] = make_pair(x,y); 
      if(i == a){ 
        ra = x; 
        sa = y; 
      } 
      if(i == b){ 
        rb = x; 
        sb = y; 
      } 
    } 
     
    for(int i = 0; i < k; i++){ 
      sola = min(sola, abs(pairs[i].first - ra) + abs(pairs[i].second - sa)); 
      solb = min(solb, abs(pairs[i].first - rb) + abs(pairs[i].second - sb)); 
    } 
    cout << min(sola + solb, abs(ra - rb) + abs(sa - sb)); 
    cout << endl; 
  } 
   
  return 0; 
}