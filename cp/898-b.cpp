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

#define _Htruong48_ main()

const int MOD = 1e9 + 7;

void fun (int &a, int &b) {
  if (a > 5) a = 11 - a;
  if (b > 5) b = 11 - b;
}


void solve(){
	int n,k;
    cin>>n>>k;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for (int i=0;i<n;i++){
        cin>>arr2[i];
    }
    for (int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int i=0;
    int j=0;
    int ans=0;
    long long sum=0;
    while(j<n){
        sum+=arr2[j];
        if(i!=j){
            if(arr1[j-1]%arr1[j]!=0){
                i=j;
                sum=arr2[j];
            }
        }
        while(sum>k){
            sum-=arr2[i];
            i++;
        }
        ans=max(ans,j-i+1);
        j++;
    }
    cout<<ans<<"\n";
}
_Htruong48_ {
	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}
}