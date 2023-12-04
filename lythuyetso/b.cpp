#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
const int  MOD =  int(1e9+7);

// (a * b) % c = ((a % c) * (b % c)) % c
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    ll factorial = 1;
    for (int i = 1; i <= n; i++){
        factorial *= i;
        factorial %= MOD;
    }
    cout << factorial;
}