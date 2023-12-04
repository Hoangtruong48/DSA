#include <bits/stdc++.h>

using namespace std;

class Arrays
{
private:
	vector<string> arrayA=  {"dog","cat","rat","fox","frog", "dinosaur","cow","bull"};
	vector<string> arrayB = {"dog", "dog", "cat","dog","frog","rat","turtle","fox","fox","man","man","frog","man"};
public:
	Arrays(){};
	void compare(){
		set<string> se(arrayA.begin(), arrayA.end());
		map<string, int> mp;
		for (string x : arrayB){
			if (se.find(x) != se.end()){
				mp[x]++;
			}
		}
		for (auto x : mp){
			cout << x.first << " " << x.second << endl;
		}
	}
};

int main(){
	Arrays a;
	a.compare();
	
}