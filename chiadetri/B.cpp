#include <bits/stdc++.h>

using namespace std;


void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    for (long long &x : a)
        cin >> x;
    sort(a, a + n);
    if (n == 1){
        if (a[0] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    if (a[0] != 1 || a[1] != 1){
        cout << "NO\n";
        return;
    }
    long long s = 2;
    for (int i = 2; i < n; i++){
        if (a[i] > s){
            cout << "NO\n";
            return;
        }
        s += a[i];
    }
    cout << "YES\n";
    
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