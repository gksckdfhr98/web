#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

int T;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		int num1 = stoi(s.substr(0, 2));
		int num2 = stoi(s.substr(2, 2));
		if (1 <= num1 && num1 <= 12) {
			if (1 <= num2 && num2 <= 12) {
				cout << "#" << t << " AMBIGUOUS\n";
			}
			else {
				cout << "#" << t << " MMYY\n";
			}
		}
		else {
			if (1 <= num2 && num2 <= 12) {
				cout << "#" << t << " YYMM\n";
			}
			else {
				cout << "#" << t << " NA\n";
			}
		}
	}
	return 0;

}
