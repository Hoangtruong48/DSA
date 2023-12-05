#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n, k, ok = 1, a[1002];
void khoitao(){
	for (int i = 1; i <= k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
		--i;
	}
	if (i == 0){
		ok = 0;
	}
	else{
		a[i]++;
		for (int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
	}
}
int check(int a[], int b[], int k){
	for (int i = 1; i <= k; i++){
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int tohop(int n, int k){
	k = min(k, n - k);
	int res = 1;
	for (int i = 1; i <= k; i++){
		res *= (n - k + i);
		res /= i;
	}
	return res;
}


int main(){
		
}