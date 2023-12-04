#include<bits/stdc++.h>

using namespace std;

bool sokhopchuoi(string s1, string s2)
{
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
	return false;
}



int main(){

	int n = 9, k = 150;
	int dp[10][151];
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++){
			dp[i][j] = 0;
		}
	}

	int v[n], w[n];

	for (int i = 1; i <= n; i++){
		v[i] = rand() % 12;
		w[i] = rand() % 50;
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << dp[n][k] << endl;

	string s1 = "it6088";
	string s2 = "ssit6088";

	if (s1.size() < s2.size()){
		swap(s1, s2);
	}

	cout << sokhopchuoi(s1, s2);
	return 0;
}