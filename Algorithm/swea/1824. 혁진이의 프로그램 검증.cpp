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

int R, C;
int visit[20][20][16][4];
int fail[20][20][16][4];
// top, right, bottom, left : 0,1,2,3

int solve(string code[],int x, int y, int mem, int dir) {
	bool result;

	if (code[x][y] == '@')return true;
	if (visit[x][y][mem][dir]==1) return false;
	if (fail[x][y][mem][dir]==1) return false;

	visit[x][y][mem][dir] = 1;
	if (code[x][y] == '<') result = solve(code,x, (y - 1 + C) % C, mem, 3);
	else if (code[x][y] == '>') result = solve(code,x, (y + 1) % C, mem, 1);
	else if (code[x][y] == '^')result = solve(code,(x - 1 + R) % R, y, mem, 0);
	else if (code[x][y] == 'v')result = solve(code, (x + 1) % R, y, mem, 2);
	else if (code[x][y] == '_') {
		if (mem == 0) result = solve(code, x, (y+1)%C, mem, 1);
		else result = solve(code, x, (y-1+C)%C, mem, 3);
	}
	else if (code[x][y] == '|') {
		if (mem == 0)result = solve(code, (x+1)%R, y, mem, 2);
		else result = solve(code, (x-1+R)%R, y, mem, 0);
	}
	else if (code[x][y] == '?') {
		result = solve(code, (x-1+R)%R, y, mem, 0) || solve(code, x, (y+1)%C, mem, 1) 
			|| solve(code, (x+1)%R, y, mem, 2) || solve(code, x, (y-1+C)%C, mem, 3);
	}
	else {
		int newmem;
		if ('0' <= code[x][y] && code[x][y] <= '9') newmem = (int)(code[x][y]-'0');
		else if (code[x][y] == '+') newmem = (mem + 1) % 16;
		else if (code[x][y] == '-')newmem = (mem - 1 + 16) % 16;
		else newmem = mem;
		switch (dir)
		{
		case 0:
			result = solve(code, (x - 1 + R) % R, y, newmem, 0);
			break;
		case 1:
			result = solve(code, x, (y + 1) % C, newmem, 1);
			break;
		case 2:
			result = solve(code, (x + 1) % R, y, newmem, 2);
			break;
		case 3:
			result = solve(code, x, (y - 1 + C) % C, newmem, 3);
			break;
		}
	}
	visit[x][y][mem][dir] = 0;
	if (!result) fail[x][y][mem][dir] = 1;
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> R >> C;
		string code[21];
		for (int i = 0; i < R; i++) {
			cin >> code[i];
		}

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				for (int k = 0; k < 16; k++)
					for (int l = 0; l < 4; l++)
						visit[i][j][k][l] = fail[i][j][k][l] = false;
	

		if (solve(code,0, 0, 0, 1))
			printf("#%d YES\n", tc);
		else
			printf("#%d NO\n", tc);
	}
	return 0;

}
