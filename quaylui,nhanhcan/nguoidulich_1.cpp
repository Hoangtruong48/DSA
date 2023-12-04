#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;

const double pi = 3.1415926535897932384626433832795;

int main()
{
	cout << fixed << setprecision(9);
	double a, r;
	cin >> a >> r;
	double p = (r +  r + a) / 2;
	cout << pi * r * r / 2 - sqrt(p * (p - r) * (p - r) * (p - a));
}