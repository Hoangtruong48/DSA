#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool nto(int n){
    if (n < 2)
        return false;
    else{
        for (int i = 2; i <= sqrt(n); i++){
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

int tong(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int tongchan(int n){
    int sum = 0;
    while(n){
        int r = n % 10;
        if (r % 2 == 0)
            sum += r;
        n /= 10;
    }
    return sum;
}

int tongnto(int n){
    int sum = 0;
    while (n){
        int r = n % 10;
        if (r == 2 || r == 3 || r == 5 || r == 7)
            sum += r;
        n /= 10;
    }
    return sum;
}

int latnguoc(int n){
    int a = 0;
    while(n){
        a = a * 10 + n % 10;
        n /= 10;
    }
    return a;
}

int sluoc(int n){
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            cnt++;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if (n > 1)
        cnt++;
    return cnt;
}

int uocln(int n){
    int uoc = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            uoc = i;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if (n > 1)
        uoc = n;
    return uoc;
}

int so6(int n){
    while(n){
        int r = n % 10;
        if (r == 6)
            return 1;
        n /= 10;
    }
    return 0;
}

bool chiahet8(int n){
    return tong(n) % 8 == 0;
}

int giaithua(int n){
    if (n == 1 || n == 0)
        return 1;
    else return n * giaithua(n - 1);
}
int tonggiaithua(int n){
    int sum = 0;
    while(n){
        int r = n % 10;
        sum += giaithua(r);
        n /= 10;
    }
    return sum;
}
bool tao1so(int n){
    int r = n % 10;
    n /= 10;
    while(n){
        int a = n % 10;
        if (a != r)
            return false;
        n /= 10;
    }
    return true;
}
bool a12(int n){
    int a = n % 10;
    n /= 10;
    while(n){
        int r = n % 10;
        if (r > a)
            return false;
        n /= 10;
    }
    return true;
}

int mu(int n, int m){
    if (m == 1)
        return n;
    if (m % 2 == 0)
        return mu(n, m / 2) * mu(n, m / 2);
    else return n * mu(n, m / 2) * mu(n, m / 2);
}

int a13(int n){
    int temp = n, dem = 0;
    while(temp){
        dem++;
        temp /= 10;
    }
    int sum = 0;
    while(n){
        int r = n % 10;
        sum += mu(r, dem);
        n /= 10;
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << nto(n) << endl;
    cout << tong(n) << endl;
    cout << tongchan(n) << endl;
    cout << tongnto(n) << endl;
    cout << latnguoc(n) << endl;
    cout << sluoc(n) << endl;
    cout << uocln(n) << endl;
    cout << so6(n) << endl;
    cout << chiahet8(n) << endl;
    cout << tonggiaithua(n) << endl;
    cout << tao1so(n) << endl;
    cout << a12(n) << endl;
    cout << a13(n);

}