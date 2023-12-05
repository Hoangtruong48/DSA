#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int ok = 1, a[11], n;

void khoitao(){
	for (int i = 1; i <= n; i++)
		a[i] = 0;
}

void sinh(){
	int i = n;
	while(i >= 0 && a[i] == 1){
		a[i] = 0;
		--i;
		
	}
	if (i == 0)
		ok = 0;
	else{
		a[i] = 1;
	}
}
int main(){
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	while(ok){
		for (int i = 1; i <= n; i++){
			cout << s[i - 1] << " ";
		}
		cout << endl;
		sinh();
	}


}