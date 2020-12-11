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
using namespace std;

int T;
int N, K;

int fac(int num, int res) {
	if (num == 1) return res;
	else {
		res *= num;
		fac(num - 1, res);
	}
}

void dfs(vector<int> num, vector<bool> &visited, long long &cnt, long long &score, int d) {
	if (d == N) {
		if (score >= K) cnt++;
		return;
	}
	if (score>=K) {
		int rest = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) rest++;
		}
		cnt += (long long)fac(rest, 1);
		return;
	}
	for (int i = N-1; i >= 0; i--) {
		if (!visited[i]) {
			visited[i] = true;
			score += max(num[d], i + 1);
			dfs(num, visited, cnt, score, d + 1);
			score -= max(num[d], i + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		vector<int> num(N);
		vector<bool> visited(N,0);
		for (int i = 0; i < N; i++) {
			num[i] = i + 1;
		}
		int ans = fac(N, 1);
		long long cnt = 0, score = 0;
		dfs(num,visited,cnt,score,0);

		cout << "#" << t << " " << ans * cnt << "\n";
	}
	return 0;

}
