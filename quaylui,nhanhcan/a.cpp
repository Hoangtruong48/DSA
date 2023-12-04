#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

char x[100];
char c;
int n, k, a[100];
bool used[1000];

void inkq(){
	for (int i = 1; i <= k; i++)
		cout << a[i];
	cout << endl;
}

void backTracking(int i){
	for (int j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if (i == k)
			inkq();
		else
			backTracking(i + 1);
	}
}
bool isVowel(char c){
	return c == 'E' || c == 'A';
}

bool check(){
	for (int i = 2; i < n; i++){
		if (!isVowel(x[i - 1]) && !isVowel(x[i + 1]) && isVowel(x[i]))
			return false;
	}
	return true;
}

void print(){
	for (int i = 1; i <= n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int i){
	for (int j = 'A'; j <= c; j++){
		if(!used[j]){
			x[i] = j;
			used[j] = true;
			if (i == n){
				if(check()){
					print();
				}
			}
			else
				Try(i + 1);
			used[j] = false;
		}
		
	}
}

int main(){
	cin >> n >> k;
	memset(used, false, sizeof(used));
	backTracking(1);
}