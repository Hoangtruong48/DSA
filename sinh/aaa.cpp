#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

map<int, long long> mp1;
long long g(int n){
	if (n < 4)
		return n;
	if (mp1.find(n) == mp1.end()){
		int k = n / 4;
		long long v = g(3 * k);
		if (n % 4 == 1)
			v += g(3 * k + 1);
		else if (n % 4  == 2 )
			v += g(3 * k + 2);
		else if (n % 4 == 3)
			v += g(3 * k + 3);
		mp1[n] = v;
	}
	return mp1[n];
}
int main()
{
	int n;
	cin >> n;
	cout << g(n);
}