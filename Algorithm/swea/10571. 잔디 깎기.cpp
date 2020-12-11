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


int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> land(N, vector<int>(M));
		int row[101], col[101];
		for (int i = 0; i < N; i++) {
			row[i] = 100;
			for (int j = 0; j < M; j++) {
				col[j] = 100;
				cin >> land[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int tmp = 100 - land[i][j];
				row[i] = min(row[i], tmp);
				col[j] = min(col[j], tmp);
			}
		}
		bool res = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int tmp = max(row[i], col[j]);
				tmp = 100 - tmp;
				if (land[i][j] != tmp) {
					res = false;
					break;
				}
			}
		}
		if (res) {
			cout << "#" << t << " YES\n";
		}
		else cout << "#" << t << " NO\n";
	}
	return 0;

}
