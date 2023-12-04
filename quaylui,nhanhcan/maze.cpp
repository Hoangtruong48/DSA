#include <bits/stdc++.h>

using namespace std;
int n;
int a[100][100];
bool c = 0;
string s = "";

void input(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

void solve(int i, int j){
	if (i == n && j == n){
		c = 1;
		cout << s << endl;
	}
	if (n >= i + 1 && a[i + 1][j]){
		s += 'D';
		a[i + 1][j] = 0;
		solve(i + 1, j);
		s.pop_back();
		a[i + 1][j] = 1;
		
	}
	if (i >= 2 && a[i][j - 1]){
		s += 'L';
		a[i][j - 1] = 0;
		solve(i , j - 1);
		s.pop_back(); 
		a[i][j - 1] = 1;
		
	}
	if (n >= j + 1 && a[i][j + 1]){
		s += 'R';
		a[i][j + 1] = 0;
		solve(i, j + 1);
		s.pop_back();
		a[i][j + 1] = 1;
		
	}
	if (j >= 2 && a[i - 1][j]){
		s += 'U';
		a[i - 1][j] = 0;
		solve(i - 1, j);
		s.pop_back();
		a[i - 1][j] = 1;
		
	}
}

int main(){
	input();
	solve(1, 1);
	if (c == 0)
		cout << -1;
	return 0;
}