#include <bits/stdc++.h>

using namespace std;

int vitri = -1;
int lonnhat = -1;
struct manhinh
{
	string ten;
	int kichthuoc;
	int trongluong;
};

void manhinhlonnhat(manhinh a[], int l, int r){
	 if (l == r){
        if (a[l].kichthuoc > lonnhat){
            lonnhat = a[l].kichthuoc;
            vitri = l;
        }
    }
    else{
        int m = (l + r) / 2;
        manhinhlonnhat(a, l , m);
        manhinhlonnhat(a, m + 1, r);
    }
}

int main(){
	manhinh a[7];
	a[1] = {"Acer", 16, 5};
	a[2] = {"Dell", 18, 6};
	a[3] = {"Lenovo", 16, 5};
	a[4] = {"Samsung", 24, 8};

	manhinhlonnhat(a, 1, 4);
	cout << "Vi tri thu " << vitri << "co man hinh lon nhat " << endl;
	cout << "Man hinh co kich thuoc lon nhat la:" << a[vitri].ten << " " << a[vitri].kichthuoc << " " << a[vitri].trongluong << endl;

	int m = 13;

	int w[5], v[5];
	for (int i = 1; i <= 4; i++){
		w[i] = a[i].trongluong;
		v[i] = a[i].kichthuoc;
	}

	int dp[4 + 1][14];
	for (int i = 0; i <= 4; i++){
		for (int j = 0; j <= 13; j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 13; j++){
			dp[i][j]  = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << "Tong kich thuoc lay duoc nhieu nhat la:" <<  dp[4][13];

	return 0;
}