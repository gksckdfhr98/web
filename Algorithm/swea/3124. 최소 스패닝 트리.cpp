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

int V, E;
int A, B, C;
long long ans;

int parent[100001];



int getParent(int n) {
	if (parent[n] == n) return n;
	return getParent(parent[n]);
}

void unionParent(int a,int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool isCycle(int a,int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)return true;
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
		cin >> V >> E;
		memset(parent, 0, sizeof(parent));
		ans = 0;
		vector< pair< int,pair<int, int>>> edge;
		for (int i = 0; i < E; i++) {
			cin >> A >> B >> C;
			edge.push_back({ C,{A,B} });
		}
		sort(edge.begin(), edge.end());

		for (int i = 1; i <= V; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < edge.size(); i++) {
			if (!isCycle(edge[i].second.first,edge[i].second.second)) {
				ans += edge[i].first;
				unionParent(edge[i].second.first, edge[i].second.second);
			}
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;

}
