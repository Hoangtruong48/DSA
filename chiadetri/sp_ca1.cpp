#include <bits/stdc++.h>

using namespace std;


int vitri = -1;
int Max = -1;
struct dogiadung
{
	string ten;
	int kichthuoc;
	int giatri;
};

void kichthuoclonnhat(dogiadung a[], int l, int r){
	if (l == r){
		if (a[l].kichthuoc > Max){
			Max = a[l].kichthuoc;
			vitri = l;
		}
	}
	else{
		int mid = (l + r) / 2;
		kichthuoclonnhat(a, l, mid);
		kichthuoclonnhat(a, mid + 1, r);
	}
};

int main(){
	
	int n = 5;
	dogiadung a[n];
	a[1] = {"chao chong dinh", 4 , 2};
	a[2] = {"bep dien tu",6 , 8};
	a[3] = {"noi lau dien",5 , 10};
	a[4] = {"bo noi cao cap",3 , 8};

	kichthuoclonnhat(a, 1, 4);

	cout << "Vi tri do gia dung co kich thuoc lon nhat la:" << vitri << endl;
	cout << "Thong tin do gia dung co kich thuoc lon nhat la:" << endl;
	cout << a[vitri].ten << " " << a[vitri].kichthuoc << " " << a[vitri].giatri << endl;

	int v1 = 16;

	int w[5], v[5];
	for (int i = 1; i <= 4; i++){
		w[i] = a[i].kichthuoc;
		v[i] = a[i].giatri;
	}

	int dp[4 + 1][17];
	for (int i = 0; i <= 4; i++){
		for (int j = 0; j <= 17; j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 17; j++){
			dp[i][j]  = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << "Tong gia tri lay duoc nhieu nhat la:" <<  dp[4][17];

	return 0;
}