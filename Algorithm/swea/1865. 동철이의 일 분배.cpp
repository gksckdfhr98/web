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
double m[17][17];
bool work[17];
double ans;
bool max_ans;

void dfs(int n, double p) {
	if (n == N + 1) {
		if (max_ans) {
			ans = max(ans, p);
		}
		else {
			ans = p;
			max_ans = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!work[i]) {
			double next = p * m[n][i];
			if (max_ans) {
				if (ans < next) {
					work[i] = true;
					dfs(n + 1, p*m[n][i]);
					work[i] = false;
				}
			}
			else {
				work[i] = true;
				dfs(n + 1, p*m[n][i]);
				work[i] = false;
			}
		}
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
		memset(work, 0, sizeof(work));
		ans = 0;
		max_ans = false;
		cin >> N;
		for(int i=1;i<=N;i++)
			for (int j = 1; j <= N; j++) {
				cin >> m[i][j];
				m[i][j] /= 100.0;
			}
		dfs(1, 1.0);
		printf("#%d %.6lf\n", tc, ans*100);
	}
	return 0;

}
