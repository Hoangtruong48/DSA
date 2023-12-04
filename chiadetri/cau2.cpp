#include<bits/stdc++.h>

using namespace std;

struct hocphan
{
	string malop;
	int sohs;
	int sohsnu;
};
bool xulyxau(string s1, string s2){
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
	int n = 75, k = 150;
	hocphan a[9];
	a[1] = {"it6001",70 ,25};
	a[2] = {"it6002",69,15};
	a[3] = {"BS6002",65,30};
	a[4] = {"BS6009",64,24};
	a[5] = {"it6095",62,10};
	a[6] = {"BS6024",60,21};
	a[7] = {"it6016",55,6};
	a[8] = {"it6055",48,2};

	int dem = 0;
	int tong = 0;
	for (int i = 1; i < 9; i++){
		tong += a[i].sohs;
		dem++;
		if (tong > n){
			break;
		}
	}

	cout << "Can lay it nhat " << dem << " lop de co so hoc sinh lon hon " << n << endl;

	int v[9], w[9];
	
	for (int i = 1; i < 9; i++){
		w[i] = a[i].sohs;
		v[i] = a[i].sohsnu;
	}

	int dp[9][151];

	for (int i = 0; i <= 8; i++){
		for (int j = 0; j <= 150; j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= 150; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << "Tong lay duoc nhieu nhat so hoc sinh nu la:" << dp[8][150] << endl;

	string xau = "it";

	for (int i = 1; i < 9; i++){
		if (xulyxau(a[i].malop, xau)){
			cout << a[i].malop << " " << a[i].sohs << " " << a[i].sohsnu << endl;
		}
	}

	int size_lop = 8;
	vector<int> Luu;
	while(size_lop != 0){
		if (dp[size_lop][k] != dp[size_lop - 1][k]){
			Luu.push_back(size_lop);
			k -= a[size_lop - 1].sohs;
		}
		size_lop--;
	}
	cout << endl;
	for (int x : Luu)
		cout << x <<  " ";

	

	/*vector<Lop> res;
    while(size_x != 0)
    {
        if(dp[size_x][k] != dp[size_x - 1][k])
        {
            res.push_back(x[size_x-1]);
            k -= x[size_x - 1].soHocSinh;
        }
        size_x--;
    }
    return res;*/
	return 0;
}