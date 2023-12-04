#include <bits/stdc++.h>

using namespace std;

vector<int> v1;
vector<int> v2;

struct giaotrinh
{
	string ten;
	string tentg;
	float giabia;
};

float tong = 0;
int dem = 0;

void tonggiatrisach(giaotrinh g[], int l, int r){
	if (l == r){
		if (g[l].giabia <= 100000){
			tong += g[l].giabia;
		}
	}
	else{
		int m = (l + r) / 2;
		tonggiatrisach(g, l, m);
		tonggiatrisach(g, m + 1, r);
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
	giaotrinh g[5];
	g[0] = {"Dac nhan tam", "Carager", 150000};
	g[1] = {"Tri tue do thai", "Carager John", 50000};
	g[2] = {"DSA", "Hugo", 60000};
	tonggiatrisach(g, 0, 2);
	cout << "Tong gia tri sach:" << tong;

	string t = "Carager";
	cout << endl;
	cout << "Cac quyen sach co ten tg la:" << endl;
	for (int i = 0; i < 3; i++){
		if (sokhopchuoi(g[i].tentg, t)){
			cout << g[i].ten << " " << g[i].tentg << " " << g[i].giabia << endl;
		}
	}

	return 0;
}