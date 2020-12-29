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

int N;
int w[10];
bool visit[10];
int ans;
float half;
int factorial[10];

void getFactorial() {
	factorial[0] = 1;
	factorial[1] = 1;
	factorial[2] = 2;
	for (int i = 3; i <= 10; i++) factorial[i] = factorial[i - 1] * i;
	for (int i = 0; i <= 10; i++) factorial[i] = pow(2, i)*factorial[i];
}

void dfs(int left, int right, int cnt) {
	if (cnt == N) {
		ans++;
		return;
	}

	if (left >= half) {
		ans += factorial[N - cnt];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i])continue;
		visit[i] = true;
		dfs(left + w[i], right, cnt + 1);
		if (left >= right + w[i]) dfs(left, right + w[i], cnt + 1);
		visit[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	getFactorial();
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		memset(w, 0, sizeof(w));
		memset(visit, 0, sizeof(visit));
		half = 0;
		for (int i = 0; i < N; i++) {
			cin >> w[i];
			half += w[i];
		}
		half /= 2;
		ans = 0;
		dfs(0, 0, 0);
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
