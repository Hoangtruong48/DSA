#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int x, y, g;

void extended_gcd(int a, int b){
	if (b == 0){
		g = a; // ucln
		x = 1;
		y = 0;
		return;
	}
	extended_gcd(b, a % b);
	int tmp = x;
	x = y;
	y = tmp - a / b * y;

}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    extended_gcd(15, 8);
    if (g != 1){
    	cout << "Khong ton tai nghich dao module";
    }
    else cout << (x % 8 + 8) % 8;
    
    return 0;
}