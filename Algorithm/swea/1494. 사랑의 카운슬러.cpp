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
#include<cmath>
using namespace std;

int N;
bool chk[22];
long long ans;
vector< pair<int, int> > num;
void dfs(int n, int s) {
	if (n == N / 2) {
		long long x = 0, y = 0;
		for (int i = 0; i < N; i++) {
			if (chk[i]) {
				x += num[i].first;
				y += num[i].second;
			}
			else {
				x -= num[i].first;
				y -= num[i].second;
			}
		}
		if (x*x + y * y < ans) ans = x * x + y * y;
		return;
	}
	for (int i = s; i < N; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		dfs(n + 1, i);
		chk[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		memset(chk, 0, sizeof(chk));
		ans = LLONG_MAX;
		num.clear();
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			num.push_back({ a,b });
		}
		dfs(0, 0);
		printf("#%d %lld\n", tc, ans);
	}
	return 0;

}
