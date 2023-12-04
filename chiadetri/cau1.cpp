#include<bits/stdc++.h>

using namespace std;

int res = -1;
int m = (int) 2e9 + 7;
void timsonhonhat(int a[], int l, int r, int k){
	if (l == r){
		if (a[l] > k && a[l] < m){
			res = a[l];
			m = a[l];
		}
	}
	else{
		int mid = (l + r) / 2;
		timsonhonhat(a, l, mid, k);
		timsonhonhat(a, mid + 1, r, k);
	}
}
int main(){
	int k = 10;
	int a[16] = {1, 2, 3, 4, 9, 10 , 12, 15, 2, 3, 4, 10, 11, 12, 15};
	timsonhonhat(a, 0, 14, k);
	cout << res;

	return 0;
}