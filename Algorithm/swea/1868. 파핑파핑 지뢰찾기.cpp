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
string m[301];
bool visit[301][301];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
int click;


bool find_zero(int x, int y) {
	bool result = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (m[nx][ny] == '*') {
			result = false;
			break;
		}
	}
	return result;
}

void play() {
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && m[i][j] == '.' && find_zero(i, j)) {
				click++;
				queue< pair<int, int> > q;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					visit[x][y] = true;
					for (int i = 0; i < 8; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
						if (visit[nx][ny]) continue;
						visit[nx][ny] = true;
						if (find_zero(nx, ny)) q.push({ nx,ny });
					}
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
		memset(visit, 0, sizeof(visit));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		click = 0;
		play();
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && m[i][j] == '.') click++;
			}
		printf("#%d %d\n", tc, click);
	}
	return 0;

}
