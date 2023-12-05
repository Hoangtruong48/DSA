#include <bits/stdc++.h>

using namespace std;

struct aokhoac
{
	string nhanhieu;
	string kieudang;
	float gia;
};

float tong = 0;
int dem = 0;
vector<int> luu1, luu2;

void tonggiatriao(aokhoac g[], int l, int r){
	if (l == r){
		if (a[i].gia < 500000){
			tong += a[i].gia;
			dem++;
		}
	}
	else{
		int m = (l + r) / 2;
		tonggiatriao(a, l, m);
		tonggiatriao(a, m + 1, r);
	}
}

bool sokhopchuoi(string s1, string s2){
	int cnt = 0, cnt1 = 0;
    int n = s1.size();
    int n1 = s2.size();

    for (int i = 0; i < n; i++){
        int temp = i;
        for (int j = 0; j < n1; j++){
            if (s1[temp] == s2[j]){
                temp++;
                cnt1++;
            }
            else{
                cnt1 = 0;
                break;
                
            }
            if (cnt1 == n1){
                cnt++;
                cnt1 = 0;
            }
                
        }
    }
    if (cnt != 0)
    	return true;
    else return false;

}
int main(){
	aokhoac a[3];

	a[0] = {"adidas", "ao co lot long", 560000};
	a[1] = {"nike", "ao gio", 420000};
	a[2] = {"gucci", "ao da", 200000 };

	tonggiatriao(a, 0, 2);

	if (dem!=0){
		cout << "TOng gia tri cac ao la:" << tong << endl;
		cout << "GIa tri trung binh la:" << tong/dem <<endl;
	}
	else{
		cout << "khong co ao nao nho hon 500000" << endl;
	}

	int dem1 = 0;
	string h = "ao gio";
	for (int i = 0; i <=2; i++){
		if (sokhopchuoi(h, a[i].nhanhieu)){
			dem++;
			cout << a[i].nhanhieu << " " << a[i].kieudang << " " << a[i].gia << endl;
		}
	}

	if (dem1 == 0){
		cout << "Khong co ao nao trung voi" << h << endl;
	}

	
}