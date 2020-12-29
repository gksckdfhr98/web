#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<unordered_map>
#include<string>
#include<cstdlib>
#include<limits.h>
#include<cstring>
#include<math.h>
#include<string.h>
#include<cmath>
using namespace std;

string A, B;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> A >> B;
		int i = 0;
		int ans = A.length();
		while (i < ans) {
			if (A.find(B) != string::npos) {
				i = A.find(B) + B.length();
				ans = ans - B.length() + 1;
				A = A.substr(i);
			}
			else break;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
