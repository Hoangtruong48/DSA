#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



#define pb push_back
//#define push_back emplace_back
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define mp make_pair

const int MOD = 1e9 + 7;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<pair<int, vector<string>>> mp;
        mp.push_back(std::make_pair(2, std::vector<std::string>{"a", "b", "c"}));
	    mp.push_back(std::make_pair(3, std::vector<std::string>{"d", "e", "f"}));
	    mp.push_back(std::make_pair(4, std::vector<std::string>{"g", "h", "i"}));
	    mp.push_back(std::make_pair(5, std::vector<std::string>{"j", "k", "l"}));
	    mp.push_back(std::make_pair(6, std::vector<std::string>{"m", "n", "o"}));
	    mp.push_back(std::make_pair(7, std::vector<std::string>{"p", "q", "r", "s"}));
	    mp.push_back(std::make_pair(8, std::vector<std::string>{"t", "u", "v"}));
	    mp.push_back(std::make_pair(9, std::vector<std::string>{"w", "x", "y", "z"}));
        for (auto x : mp){
        	cout << x.first << " - ";
        	for (auto yt : x.second){
        		cout << yt << " ";
        	}
        	cout << endl;
        }
    }

};
int main(){
	vector<pair<int, vector<string>>> mp;
        mp.push_back(std::make_pair(2, std::vector<std::string>{"a", "b", "c"}));
	    mp.push_back(std::make_pair(3, std::vector<std::string>{"d", "e", "f"}));
	    mp.push_back(std::make_pair(4, std::vector<std::string>{"g", "h", "i"}));
	    mp.push_back(std::make_pair(5, std::vector<std::string>{"j", "k", "l"}));
	    mp.push_back(std::make_pair(6, std::vector<std::string>{"m", "n", "o"}));
	    mp.push_back(std::make_pair(7, std::vector<std::string>{"p", "q", "r", "s"}));
	    mp.push_back(std::make_pair(8, std::vector<std::string>{"t", "u", "v"}));
	    mp.push_back(std::make_pair(9, std::vector<std::string>{"w", "x", "y", "z"}));
        for (auto x : mp){
        	cout << x.first << " - ";
        	for (auto yt : x.second){
        		cout << yt << " ";
        	}
        	cout << endl;
        }
	return 0;
}