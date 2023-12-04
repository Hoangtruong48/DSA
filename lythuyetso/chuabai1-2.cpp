#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

bool check(int n)
{
	int temp = n, lat = 0;
	while (temp != 0){
		lat = lat * 10 + temp % 10;
		temp /= 10;
	}
	if (lat == n)
		return true;
	return false;
}
bool check1(int n)
{
	int cnt = 0;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			++cnt;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if (n > 1)
		cnt++;
	return cnt >= 3;
}
bool hoanhao(ll n) // time limit
{
	ll sum = 1;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			sum += i;
			if (i != n / i){
				sum += n / i;
			}
		}
	}
	if (sum == n)
		return true;
	return false;
}
bool nguyento(ll n){
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

 ll ans[100];
 int counthh = 0;

 void init()
 {
 	for (int p = 1; p <= 31; p++){
 		if (nguyento(p)){
 			ll tmp = (ll)pow(2, p) - 1;
 			if (nguyento(tmp)){
 				ll tich = (ll)pow(2, p - 1) * tmp;
 				ans[counthh] = tich;
 				counthh++; 
 			}
 		}
 	}
 }
 bool tong(int n)
 {
 	int t = 0;
 	while (n != 0){
 		t += n % 10;
 		n /= 10;
 	}
 	return t % 10 == 8;
 }
 bool check2(int n)
 {
 	while (n != 0){
 		int a = n % 10;
 		if (a == 6)
 			return true;
 		n /= 10;
 	}
 	return false;
 }
 bool chusocuoi(int n)
 {
 	int r = n % 10;
 	while (n != 0){
 		if (n % 10 > r)
 			return false;
 		n /= 10;
 	}
 	return true;
 }
 bool a[10000001];
 void eratosthenes(){
 	for (int i = 0; i <= 1e7; i++)
 		a[i] = true;
 	a[0] = a[1] = false;
 	for (int i = 2; i <= sqrt(1e7); i++){
 		for (int j = i * i; j <= 1e7; j += i){
 			a[j] = false;
 		}
 	}
 }
long long tamgiac[100][100];
void init1(){
	for (int i = 0; i < 100; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0 || i == j){
				tamgiac[i][j] = 1;
			}
			else{
				tamgiac[i][j] = (tamgiac[i-1][j-1] % MOD + tamgiac[i-1][j] % MOD) % MOD;
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    init1();
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++){
    	for (int j = 0; j <= i; j++){
    		cout << tamgiac[i][j] << " ";
    	}
    	cout << endl;
    }
    
}
