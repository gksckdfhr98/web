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
int candidate[100005];

void addCandidate(int pos, int size) {
	if (pos < size) candidate[pos + 1] = true;
	if (pos > 1) candidate[pos - 1] = true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, q;
		cin >> n >> q;
		int pos = 1;
		addCandidate(pos, n);
		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;
			swap(candidate[a], candidate[b]);
			if (pos == a) pos = b;
			else if (pos == b) pos = a;
			addCandidate(pos, n);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (candidate[i]) {
				ans++;
				candidate[i] = false;
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
