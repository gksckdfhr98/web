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

int m[4][4];
bool visit[4][4];
set<int> se;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int cnt, int num) {
	if (cnt == 7) {
		se.insert(num);
		return;
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		int newnum = num * 10 + m[nx][ny];
		dfs(nx, ny, cnt + 1, newnum);
	}
	visit[x][y] = false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		se.clear();
		for(int i=0;i<4;i++)
			for (int j = 0; j < 4; j++) {
				cin >> m[i][j];
			}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 1, m[i][j]);
			}
		printf("#%d %d\n", tc, se.size());
	}
	return 0;

}
