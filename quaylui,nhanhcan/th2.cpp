#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int a[100];
int cot[100];
int n;

int xuoi[100], nguoc[100];

void init(){
	for (int i = 1; i <= n; i++){
			cot[i] = 1;
	}
}

void init2(){
	for (int i = 1; i <= 2 * n - 1; i++){
		xuoi[i] = 1;
		nguoc[i] = 1;
	}
}
int cnt = 0;

void Try(int i){
	if (i == n)
		cnt++;
	for (int j = 1; j <= n; j++){
		if (cot[j] && xuoi[i + j - 1] && nguoc[i - j + n]){
			cot[j] = 0;
			xuoi[i + j - 1] = 0;
			nguoc[i - j + n] = 0;
			Try(i + 1);
			xuoi[i + j] = 1;
			nguoc[i - j + n] = 1;
			cot[j] = 1;
		}
	}
}

int main(){
	cin >> n;
	init();
	init2();
	Try(1);
	cout << cnt;

	return 0;
}