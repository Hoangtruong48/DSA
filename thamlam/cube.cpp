#include <bits/stdc++.h>

using namespace std;

//9 19 29 39 49 59 69 79 89 99 
// 



int partition(int a[], int l, int r){
	int i = l - 1;
	int pivot = a[r];
	for (int j = l; j < r ; j++){
		if (a[j] < pivot){
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quickSort(int a[], int l, int r){
	if (l < r){
		int pos = partition(a, l , r);
		quickSort(a, l, pos - 1);
		quickSort(a, pos + 1, r);
	}
}

void merge(int a[], int l, int m, int r){
	vector<int> a1(a + l, a + m + 1);
	vector<int> a2(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < a1.size() && j < a2.size()){
		if (a1[i] <= a2[j]){
			a[l++] = a1[i++];
		}
		else{
			a[l++] = a2[j++];
		}
	}
	while (i < a1.size()){
		a[l++] = a1[i++];
	}
	while (j < a2.size()){
		a[l++] = a2[j++];
	}
}

void mergeSort(int a[], int l,int r){
	if (l < r){
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid , r);
	}
}

int main(){
	int n;
	cin >> n;
	int Array[n];
	for (int &x : Array)
		cin >> x;
	mergeSort(Array, 0, n - 1);
	for (int x : Array)
		cout << x << " ";

}