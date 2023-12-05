#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

int Gt(int a, int b){
	return sqrt(1ll* pow(a, 2) + 1ll*pow(b, 2));
}
 
int main(){
	int n, m, d;
	cin >> n >> m >> d;
	--m;
	vector<pair<int, int>> v1(n);
	int dx, dy;
	for (int i = 0; i < n; i++){
		cin >> dx >> dy;
		v1[i] = {dx, dy};
	}
	
	vector<int> index1;
	vector<int> index2;
	map<pair<int, int>, int> mp1;

	int temp = Gt(v1[m].first, v1[m].second);
	mp1[{v1[m].first, v1[m].second}] = 1;
	int f1 = 0, f2 = 0;
	vector<int> v2(n);
	for (int i = 0; i < n; i++){
		v2[i] = Gt(v1[i].first, v1[i].second);
		if (abs(v2[i] - temp) < d && mp1[{v1[i].first, v1[i].second}] == 0 ){
			f1++;
			mp1[{v1[i].first, v1[i].second}] = 1;
			if (i != m){
				index1.push_back(i);
			}
		}
		else{
			index2.push_back(i);
		}
	}
	// for (int x : index1)
	// 	cout << x << " ";
	// cout << endl;
	// for (int x : index2)
	// 	cout << x << " ";
	// cout << endl;

	for (int i = 0; i < (int)index1.size(); i++){
		temp = Gt(v1[index1[i]].first, v1[index1[i]].second);
		for (int j = 0; j < (int)index2.size(); j++){
			if (abs(temp - Gt(v1[index2[j]].first, v1[index2[j]].second)) < d && mp1[{v1[index2[j]].first, v1[index2[j]].second}] == 0){
				f2++;
				mp1[{v1[index2[j]].first, v1[index2[j]].second}] = 1;
			}
		}
	}

	cout << f1 <<  " " << f2;
}