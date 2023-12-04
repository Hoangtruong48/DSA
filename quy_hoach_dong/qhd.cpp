#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const int MOD = 1e9 + 7;
bool S[100201];

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    int dp[n + 1];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n);

    return 0;
}