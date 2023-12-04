#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
void merge(int a[], int l, int m, int r){
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int sz_x = (int)x.size(), sz_y = (int)y.size();
	int i = 0, j = 0;
	while(i < sz_x && j < sz_y){
		if (x[i] <= y[j]){
			a[l++] = x[i++];
		}
		else{
			a[l++] = y[j++];
		}
	}
	while(i < sz_x){
		a[l++] = x[i++];
	}
	while(j < sz_y){
		a[l++] = y[j++];
	}
}
void mergeSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}
void quickSort(int a[], int l, int r){
	int pivot = a[l + rand() % (r - l)];
	int i = l, j = r;
	//cout << pivot << endl;
	while(i <= j){
		while(a[i] < pivot)	i++;
		while(a[j] > pivot) j--;
		if (i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j){	
		quickSort(a, l, j);
	}
	if (r > i){	
		quickSort(a, i, r);
	} 	
}


void quickSort3(int a[], int l, int r){
	int i = l, j = r;
	int pivot = a[l + rand() % (r - l)];
	while(i <= j){
		while(a[i] < pivot)		i++;
		while(a[j] > pivot)		j--;
		if (i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j)	quickSort3(a, l, j);
	if (r > i)	quickSort3(a, i, r);
}
int partition(int a[], int l, int r)
{
	int i = l - 1;
	int pivot = a[r];
	for (int j = l; j <= r - 1; j++){
		if (a[j] < pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}
void quickSort2(int a[], int l, int r){
	if (l < r){
		int pos = partition(a, l, r);
		quickSort2(a, l, pos - 1);
		quickSort2(a, pos + 1, r);
	}
}
int main(){
	srand(time(NULL));
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		a[i] = rand() % 100;
	}
	quickSort2(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}

}
