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
int A,B;

bool check(int m) {
	int res = 0;
	while (res < m) {
		int tmp = m % 10;
		if (tmp == 0) return false;
		res = res * 10 + tmp;
		m /= 10;
	}

	return (res == m) || (res / 10 == m);
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		vector<bool> dp(1001);
		int i = 1;
		while (i*i <= B) {
			int num = i * i;
			if (i*i < 10) dp[i*i] = true;
			else {
				if (check(i*i) && check(i)) dp[i*i] = true;
			}
			i++;
		}
		int ans = 0;
		for (int j = A; j <= B; j++) {
			if (dp[j]) ans++;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
