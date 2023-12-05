#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n, k, ok = 1, a[102];
void khoitao(){
	for (int i = 1; i <= k; i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if (i == 0){
		ok = 0;
	}
	else{
		a[i] = 1;
	}
}


int main(){
	cin >> n;
	khoitao();
	vector<string> res;
	while(ok){
		string s = "";
		for (int i = 1; i <= n; i++){
			if(a[i]){
				s += to_string(i) + " ";
			}
		}
		res.push_back(s);
		sinh();
	}
	sort(res.begin(), res.end());
	for (int i = 1; i < (int)res.size(); i++)
		cout << res[i] << endl;
}