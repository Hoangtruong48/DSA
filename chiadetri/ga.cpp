#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n, q;
    cin >> n >> q;
    long long a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long pre[n + 1];
    pre[0] = 0;
    pre[1] = a[1];
    for (int i = 2; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    //for (int i = 0; i < n; i++)
        //cout << pre[i] << ' ';
    //cout << endl;
    while (q--){
        int l, r, k;
        cin >> l >> r >> k;
        long long cnt = 1ll * (r - l + 1) * k;
        long long res = pre[n] - pre[r] + pre[l - 1];
        //cout << pre[n - 1] << " " << pre[r] << " " << pre[l] << endl;
        res += cnt;
        //cout << res << " ";
        if (res % 2 == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while(tt--){
        /*cout << "Case " << tt << endl;*/
        solve();
    }
    return 0;
}