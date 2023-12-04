#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define mk make_pair
#define pb push_back
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;

ll mod = 998244353 ;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll fact[200001] ;
ll mul(ll a , ll b){
    return a * b % mod ;
}
ll power(ll a , ll b){
    ll ans = 1 , cur = a;
    while(b){
        if(b%2) ans *= cur ;
        cur *= cur ;
        cur %= mod ;
        ans %= mod ;
        b /= 2;
    }
    return ans % mod ;
}
ll divide(ll a , ll b){
    return mul(a , power(b , mod - 2)) % mod ;
}
ll nck(ll a , ll b){
    return divide(fact[a] , fact[b] * fact[a-b] % mod) % mod ;
}

const int N = 2e5 + 10 ;
string s[4] = {"DL" , "DR" , "UL" , "UR"} ; 

int get(string x){
    for(int i=0 ; i<4 ; i++) if(x == s[i]) return i ;
}
void solve(){
    
    

    int n , m ;
    cin >> n >> m ;
    vector<int> v[n*m] ;
    for(int i=0 ; i<n*m ; i++){
        v[i].resize(4) ; 
    }
    int i1 , j1 , i2 , j2 ; 
    cin >> i1 >> j1 >> i2 >> j2 ; 
    i1--,j1--,i2--,j2--;
    string curr ; 
    cin >> curr ; 
    int bounces = 0 ;
    while(1){
        // cout << i1 << " " << j1 << endl;
        if(i1 == i2 && j1 == j2){
            cout << bounces << endl;
            return;
        }
        int what = get(curr) ; 
        int c = i1 * m + j1 ;
        if(v[c][what]){
            cout << -1 << endl;
            return ;
        }
        v[c][what] = 1 ; 
        if(curr == "DR"){
            if(i1 + 1 < n && j1 + 1 < m){
                i1++;
                j1++;
            }
            else if(i1 + 1 == n && j1 + 1 < m){
                bounces++;
                curr = "UR" ; 
                i1--;
                j1++;
            }
            else if(i1 + 1 < n && j1 + 1 == m){
                bounces++;
                curr = "DL" ; 
                i1++;
                j1--;
            }
            else{
                bounces++;
                curr = "UL" ; 
                i1--;
                j1--;
            }
        }
        else if(curr == "DL"){ //i+ , j-
            if(i1 + 1 < n && j1 - 1 >= 0){
                i1++;
                j1--;
            }
            else if(i1 + 1 == n && j1 - 1 >= 0){
                bounces++;
                curr = "UL" ; 
                i1--;
                j1--;
            }
            else if(i1 + 1 < n && j1 == 0){
                bounces++;
                curr = "DR" ; 
                i1++;
                j1++;
            }
            else{
                bounces++;
                curr = "UR" ; 
                i1--;
                j1++;
            }
        }
        else if(curr == "UR"){ // i-  j+
            if(i1 > 0 && j1 + 1 < m){
                i1--;
                j1++;
            }
            else if(i1 == 0 && j1 + 1 < m){
                bounces++;
                curr = "DR" ; 
                i1++;
                j1++;
            }
            else if(i1 > 0 && j1 + 1 == m){
                bounces++;
                curr = "UL" ; 
                i1--;
                j1--;
            }
            else{
                bounces++;
                curr = "DL" ; 
                i1++;
                j1--;
            }
        }
        else if(curr == "UL"){ // i- , j-
            if(i1 > 0 && j1 > 0){
                i1--;
                j1--;
            }
            else if(i1 == 0 && j1 > 0){
                bounces++;
                curr = "DL" ; 
                i1++;
                j1--;
            }
            else if(i1 > 0 && j1 == 0){
                bounces++;
                curr = "UR" ; 
                i1--;
                j1++;
            }
            else{
                bounces++;
                curr = "DR" ; 
                i1++;
                j1++;
            }
        }
        
    }
    
    
    

}
int main() {

    int t = 1 ;
    cin >> t ;
    while(t--){
        solve();
    }


	return 0;
}
