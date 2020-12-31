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

int n, m;
int parent[1000001];

int getParent(int num) {
	if (parent[num] == num) return num;
	return getParent(parent[num]);
}

void union_element(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isSame(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> c >> a >> b;
			if (c == 0) {
				union_element(a, b);
			}
			else if (c == 1) {
				if (isSame(a, b)) {
					ans.push_back(1);
				}
				else ans.push_back(0);
			}
		}
		cout << "#" << tc << " ";
		for (int a : ans) {
			cout << a;
		}
		cout << "\n";
	}
	return 0;

}
