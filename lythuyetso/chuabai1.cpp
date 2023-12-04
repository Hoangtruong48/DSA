#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

void phantich(long long n)
{
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int mu = 0;
            while(n % i == 0){
                mu++;
                n /= i;
            }
            cout << i << "^" << mu;
            if (n != 1)
                cout << " * ";
        }
    }
    if (n > 1)
        cout << n << " ^1";
}

ll legendre(ll n, int p)
{
    ll res = 0;
    for (ll i = p; i <= n; i *= p){
        res += n / i;
        res %= MOD;
    }
    return res;
}

bool sphenic(ll n)
{
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int mu = 0;
            while (n % i == 0){
                ++mu;
                n /= i;
            }
            if (mu >= 2)
                return false;
            cnt++;
        }
    }
    if (n > 1)
        cnt++;
    return cnt == 3;

}

bool check(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int mu = 0;
            while (n % i == 0){
                mu++;
                n /= i;
            }
            if (mu <= 1){
                return false;
            }
        }
    }
    if (n > 1)
        return false;
    return true;
}
int tongchuso(int n)
{
    int a = 0;
    while (n != 0){
        a += n % 10;
        n /= 10;
    }
    return a;
}

int tongnto(int n)
{
    int a = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            while(n % i == 0){
                a += i;
                n /= i;
            }
        }
    }
    if (n > 1)
        a += n;
    return tongchuso(a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    if (tongchuso(n) == tongnto(n))
        cout << "YES";
    else cout << "NO";

}