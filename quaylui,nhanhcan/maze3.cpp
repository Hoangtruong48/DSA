#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[100][100], xuoi[100], nguoc[100], cot[100],x[100];
int cnt = 0;
int n;
long long res = 0, ans = 0;

void Try(int i){
	
	for (int j = 1; j <= 8; j++){
		if (cot[j] == 0 && xuoi[i + j - 1] == 0 && nguoc[8 + i - j] == 0){
			cot[j] = xuoi[i + j - 1] = nguoc[8 + i - j] = 1;
			ans += a[i][j];
			if (i == 8){
				res = max(res, ans);
			}
			else{	
				Try(i + 1);
			}
			cot[j] = xuoi[i + j - 1] = nguoc[8 + i - j] = 0;
			ans -= a[i][j];
		}	
	}

}

int main(){
	
	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= 8; j++){
			cin >> a[i][j];
		}
	}
	Try(1);
	cout << res;
}