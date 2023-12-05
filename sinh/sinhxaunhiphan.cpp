#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n;
int a[1026];
int ok = 1;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while (i >= 0 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << "n = ";
    cin >> n;

    while(ok){
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
    cout << endl;
    sinh();
    }
}
