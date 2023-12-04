#include <bits/stdc++.h>

using namespace std;

void noibot(int *a, int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}

void luachon(int *a, int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
    	min_idx = i;
    	for (j = i+1; j < n; j++)
        	if (arr[j] < arr[min_idx])
        		min_idx = j;
        swap(arr[min_idx], arr[i]);
	}
}

void chen(int *a, int n) {
	int index, new_number;
	for (int i = 1; i < n; i++){
		index = i;
		new_number = a[i];
		while (index > 0 && a[index - 1] > new_number){
			a[index] = a[index - 1];
			index--;
		}
		a[index] = new_number;
	}
}

int F(int m, int n){
	if (m < 0)
		return abs(m);
	else if (n <= 0)
		return F(m - 3, 1);
	else
		return F(m - 4, n) + F(m, n - 2);
}

int A(int m, int n){
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return A(m - 1, 1);
	else
		return A(m - 1, A(m, n - 1));
}
int main(){

}