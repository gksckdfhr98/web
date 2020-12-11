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
	for (int t = 1; t <= T; t++) {
		cin >> s;
		string ans = "";
		for (int i = s.length()-1; i >= 0; i--) {
			char c = s[i];
			switch (c){
				case 'b':
					ans += 'd';
					break;
				case 'd':
					ans += 'b';
					break;
				case 'p':
					ans += 'q';
					break;
				case 'q':
					ans += 'p';
					break;
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
