#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
const int MOD = 1e9 + 7;


ll powMod(int n, int k){
    if (k == 1)
        return n;
    ll temp = powMod(n, k / 2);
    if (k & 1){
        return (n % MOD * temp % MOD % MOD) * temp % MOD % MOD;
    }
    else{
        return temp % MOD * temp % MOD % MOD;
    }
}

int toInt(string s){
	return stoi(s);
}
int toReverseInt(string s){
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int n = toInt(s);
    int m = toReverseInt(s);
    cout << powMod(n, m);
    
}