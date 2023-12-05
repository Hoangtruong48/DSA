#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

//int n, k, a[100], ok = 1;

float kc(int a, int b, int c, int d){
	return sqrt(pow((a - c), 2) + pow((b - d), 2));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)->bool{
    	if (a.first == b.first)
    		return a.second < b.second;
    	return a.first < b.first;
    });
    float dp[n];
    for (int i = 0; i < n - 1; i++){
    	dp[i] = kc(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    }
    int cnt = 0;
    int cntt[n] = {0};
    for (int i = 0; i < n; i++){
    	cntt[i] = 0;
    }
    for (int i = 0; i < n - 1; i++){
    	if (dp[i] >= 1.3){
    		if (cntt[i + 1] == 0){
    			cnt += 2;
    			cntt[i + 1] = 1;
    		}
    		else 
    			cnt += 1;
    	}
    }
    cout << cnt;
}