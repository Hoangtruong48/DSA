#include<bits/stdc++.h>

using namespace std;
struct sanpham
{
	string masp;
	string tensp;
	int khoiluong;
	int giatri;
};
int vitri = 1;
void timvitrichen(sanpham a[], sanpham b, int l, int r)
{
	if (l == r){
		if (a[l].tensp < b.tensp){
			vitri = l + 1;
		}
	}
	else{
		int m = (l + r) / 2;
		timvitrichen(a, b, l, m);
		timvitrichen(a, b, m + 1, r);
	}
}
// Vị trí chèn khi ds tăng dần k làm thay đổi
int timvitrichen1(sanpham a[], sanpham b){
	int l = 0;
	int r = 8;
	while (l <= r){
		int m = (l + r) / 2;
		if (a[m].tensp > b.tensp){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return l;

}
int main(){
	sanpham a[10];
	a[1] = {"SP001","Ao khoac",1,3};
	a[2] = {"SP002","Ban pham",1,4};
	a[3] = {"SP003","Ban la",2,9};
	a[4] = {"SP004","Chuot",1,2};
	a[5] = {"SP005","Laptop",4,15};
	a[6] = {"SP006","Tai nghe",25,55};
	a[7] = {"SP007","Tu lanh",34,62};
	a[8] = {"SP0088","Vay",1,5};

	sanpham b = {"SP10", "Daa", 1, 10};

	timvitrichen(a, b, 1, 8);
	

	cout << "Vi tri chen ma k lam thay doi trat tu la " << vitri << endl;
	cout << "Vi tri chen:" << timvitrichen1(a, b);

	return 0;
}