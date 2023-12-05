#include <bits/stdc++.h>

using namespace std;

int Sum1(int n){
	int sum = 1;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			sum += i;
			if (i != (n / i)){
				sum += (n / i);
			}
		}
	}
	return sum;
}
int main(){
	int n = 1000000;
	map<int, int> mp;
	map<int, int> mp2;
	vector<pair<int, int>> v1;
	for (int i = 200; i <= n; i++){
		int res = Sum1(i);
		mp[i] = res;
	}
	for (auto x : mp){
		if (mp[x.second] == x.first && mp2.find(x.second) == mp2.end() && x.first != x.second){
			v1.push_back({x.first, x.second});
			mp2[x.first] = 1;
		}
	}
	for (auto x : v1)
		cout << x.first << " " << x.second << endl;
	return 0;
}
