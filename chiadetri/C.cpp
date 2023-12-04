#include <bits/stdc++.h>

using namespace std;

void solve(){
	int h[100];
	for (int i = 0; i < 26; i++)
		cin >> h[i];
	cin.ignore(1);
	string s;
	cin >> s;
	int h_max = -1;
	for (char x : s){
		if (h[x - 97] > h_max){
			h_max = h[x - 97];
		}
	}
	int r = (int) s.size();
	cout << h_max * r;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}