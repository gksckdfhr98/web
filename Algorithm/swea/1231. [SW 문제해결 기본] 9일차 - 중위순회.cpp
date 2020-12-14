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

int N,k,m;
char Tree[105][3],ans[105];

void solve(int n) {
	if (Tree[n][1] != NULL) {
		solve(Tree[n][1]);
	}
	ans[k] = Tree[n][0];
	k += 1;
	if (Tree[n][2] != NULL) {
		solve(Tree[n][2]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	for (int tc = 1; tc <= 10; tc++) {
		k = 0;
		for (int i = 0; i < 105; i++) {
			ans[i] = 0;
			for (int j = 0; j < 3; j++) {
				Tree[i][j] = 0;
			}
		}
		cin >> N;
		int node, left, right;
		char c;
		for (int i = 0; i < N; i++) {
			cin >> node;
			if (node * 2 + 1 <= N) {
				cin >> c >> left >> right;
				Tree[node][0] = c;
				Tree[node][1] = left;
				Tree[node][2] = right;
			}
			else if (node * 2 <= N) {
				cin >> c >> left;
				Tree[node][0] = c;
				Tree[node][1] = left;
			}
			else {
				cin >> c;
				Tree[node][0] = c;
			}
		}
		solve(1);
		m = 0;
		cout << "#" << tc << " ";
		while (ans[m] != NULL) {
			cout << ans[m++];
		}
		cout << "\n";
	}
	return 0;

}
