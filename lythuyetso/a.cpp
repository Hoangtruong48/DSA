#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long gcd(long a, long b)
{
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	else return gcd(b, a % b);
}

long long lcm(long a, long b)
{
	long long g;
	g = a / gcd(a, b) * b;
	return g;
}

long long ffff(long long n)
{
	if (n % 2 == 0)
		return n / 2;
	return n/2 - n;
}
int a[1000001];
void era()
{
	for (int i = 0; i <= 1e6; i++)
		a[i] = 1;
	a[0] = a[1] = 0;
	for (int i = 2; i <= sqrt(1e6); i++){
		for (int j = i * i; j <= 1e6; j += i){
			a[j] = 0;
		}
	}
}

bool demuoc(long long a)
{
	int cnt = 0;
	for (int i = 2; i <= sqrt(a); i++){
		if (a % i == 0){
			cnt++;
			if (i != a/i){
				cnt++;
			}
		}
	}
	return cnt % 2 == 0;
}

bool nguyento(long n)
{
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

int dem(int n)
{
	int cnt = 0;
	while(n != 0){
		++cnt;
		n /= 10;
	}
	return cnt;
}
ll fibo[93];

void fb(int n)
{
	for (int i = 0; i <= n; i++)
		fibo[i] = 0;
	fibo[0] = 0, fibo[1] = 1;
	for (int i = 2; i <=vn; i++)
		fibo[i] = (fibo[i-1] % 1000000007 + fibo[i-2] % 1000000007) % 1000000007;
}
void fb2()
{
	for (int i = 0; i <= 92; i++)
		fibo[i] = 0;
	fibo[0] = 0, fibo[1] = 1;
	for (int i = 2; i <= 92; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}

bool nto(int n)
{
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

bool tongfibo(int n)
{
	int a = 0, temp = n;
	while (temp != 0){
		a += temp % 10;
		temp /= 10;
	}
	for (int i = 0; i <= 92; i++){
		if (a == fibo[i])
			return true;
	}
	return false;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.inp", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	fb2();
	int t;
	cin >> t;
	ll n;
	while(t--){
		cin >> n;
		int c = 0;
		for (int i = 0; i <= 92; i++){
			if (fibo[i] == n){
				c = 1;
				break;
			}
		}
		if (c != 0)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}