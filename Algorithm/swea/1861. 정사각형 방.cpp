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
int m[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans_cnt,ans_start;

int solve(int x, int y) {
	int cnt = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (m[nx][ny][0] - m[x][y][0] == 1) {
			cnt += solve(nx, ny);
		}
	}
	m[x][y][1] = cnt;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(m, 0, sizeof(m));
		ans_cnt = 0;
		ans_start = 9876543;
		cin >> N;
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++) {
				cin >> m[i][j][0];
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				solve(i, j);
				if (m[i][j][1] > ans_cnt || m[i][j][1] == ans_cnt && m[i][j][0] < ans_start) {
					ans_cnt = m[i][j][1];
					ans_start = m[i][j][0];
				}

			}
		printf("#%d %d %d\n", tc, ans_start,ans_cnt);
	}
	return 0;

}
