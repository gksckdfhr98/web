#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cstdlib>
#include<limits.h>
#include<cstring>
#include<math.h>
#include<string.h>
using namespace std;

int T;
int A, B, C, D;
string res;

void solve(int a, int b, int c, int d, string s) {
	if (res != "")return;
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		res = s;
		return;
	}
	if (s[s.length() - 1] == '0') {
		if (a > 0) {
			solve(a - 1, b, c, d, s + '0');
		}
		if (b > 0 && b == c || b == c + 1) {
			solve(a, b - 1, c, d, s + '1');
		}
	}
	else {
		if (c > 0 && c == b || c == b + 1) {
			solve(a, b, c - 1, d, s + '0');
		}
		if (d > 0) {
			solve(a, b, c, d - 1, s + '1');
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B >> C >> D;
		res = "";
		solve(A, B, C, D, "0");
		solve(A, B, C, D, "1");
		if (res == "") {
			cout << "#" << t << " impossible\n";
		}
		else {
			cout << "#" << t << " " << res << "\n";
		}
	}
	return 0;

}
