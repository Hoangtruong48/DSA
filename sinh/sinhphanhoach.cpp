#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n, a[100], ok = 1, cnt = 0;

void khoitao(){
	cnt = 1;
	a[1] = n;
}

void sinh(){
	int i = cnt;
	while(i >= 1 && a[i] == 1){
		--i;
	}
	if (i == 0)
		ok = 0;
	else{
		a[i]--;
		int tmp = cnt - i + 1;
		cnt = i;
		int q = tmp / a[i];
		int r = tmp % a[i];
		if(q){
			for (int j = 1; j <= q; j++){
				a[++cnt] = a[i];
			}
		}
		if(r){
			a[++cnt] = r;
		}
	}
}

int main()
{
	cin >> n;
	khoitao();
	while(ok){
		for (int i = 1; i <= cnt; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
}