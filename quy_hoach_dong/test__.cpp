#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
auto main()->int{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	array.push_back(1e9 + 2);
	cout << *(max_element(array.begin(), array.end())) << endl;
	cout << *(prev(array.end()));
	return 0;
}