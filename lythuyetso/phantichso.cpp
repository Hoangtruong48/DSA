#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
const int  MOD =  int(1e9+7);

// (a * b) % c = ((a % c) * (b % c)) % c
void pt(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int j = 0;
            while (n % i == 0){
                j++;
                n /= i;
            }
            cout << i << " ^ " <<  j << endl;
        }
    }
    if (n > 1)
        cout << n << " ^ 1";
}

ll tonguoc(ll n)
{
    ll a = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            a += i;
            if (i != n / i){
                a += n / i;
            }
        }
    }
    return a;
}

ll tichuoc(ll n)
{
    ll a = 1;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            a *= i;
            a %= MOD;
            if (i != n/i){
                a *= n/i;
                a %= MOD;
            }
        }
    }
    return a;
}
long long tohop(int n, int k){
    ll res = 1;
    for (int i = 0; i < k; i++){
        res *= n - i;
        res /= i + 1;
    }
    return res;
}
ll c[100][100];
void init()
{
    for (int i = 0; i <= 20; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
}

int legendre(int n, int p)
{
    int res = 0;
    for (int i = p; i <= n; i *= p){
        res += n/i;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    pt(n);
    cout << endl;
    cout << tonguoc(n) << endl;
    cout << tichuoc(n) << endl;
    cout << tohop(14, 12) << endl;
    init();
    cout << legendre(30, 2);
}