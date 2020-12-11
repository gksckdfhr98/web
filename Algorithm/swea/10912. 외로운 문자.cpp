#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<string>
using namespace std;

int T;
string s;


int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> s;
		map<char, int> m;
		for (auto c : s) {
			m[c]++;
		}
		for (auto it : m) {
			it.second %= 2;
			m[it.first] = it.second;
		}
		string ans = "";
		for (auto it : m) {
			if (it.second != 0) ans += it.first;
		}
		if (ans == "") {
			cout << "#" << i << " Good\n";
		}
		else
			cout << "#" << i << " " << ans << "\n";
	}
	return 0;

}
