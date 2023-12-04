#include <bits/stdc++.h>

using namespace std;
int n;
struct sinhvien
{
	string masv, tensv, gioitinh;
	float diem;
}

vector<sinhvien> sv;
void themsv(sinhvien a){
	cout << "Nhap thong tin ma sinh vien:";	getline(cin, a.masv);
	cout << "Nhap thong tin ten sinh vien:";getline(cin, a.tensv);
	cout << "Nhap thong tin gioi tinh:";	getline(cin, a.gioitinh);
	cout << "nhap diem";	cin >> a.diem;
	sv.push_back(a);
}



int main(){
	cin.tie(0)->sync_with_stdio(0);

	return 0;
}