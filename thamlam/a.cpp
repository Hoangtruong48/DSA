#include <bits/stdc++.h>

using namespace std;
int min1 = 2e9 + 2;

void Min(int a[], int l, int r){
	int m = (l + r) / 2;
	if (l == r ){
		if (a[l] < min1 && a[l] % 2 == 0){
			min1 = a[l];
			return;
		}
	}
	else{
		int m = (l + r) / 2;
		Min(a, l, m);
		Min(a, m + 1, r);
	}
}

int binary_Search(int a[], int n, int x){
	int l = 0, r = n - 1;
	int mid = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if (a[m] == x){
			mid = m;
			r = m - 1;
		}
		else if (a[m] > x){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return mid;
}
int main(){
	int a[] = {1, 2, 3, 5, 8, 9, 4, 2, 3, 2, 3, 9};
	Min(a, 0, 11);
	cout << min1 << "\n";
	sort(a, a + 12);
	for (int x : a)
		cout << x << " ";
	cout << endl;
	int index = binary_Search(a, 12, 2);
	cout << index << "\n";

	return 0;
}