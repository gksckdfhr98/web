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

int N, M, C;
long long tree[301000];
int num[100005];
int X, Y, L, R;
vector<long long> ans;

int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, int dif) {
	if (index<start || index>end)return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(num, 0, sizeof(num));
		ans.clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
		}
		init(0, N - 1, 1);
		for (int i = 0; i < M; i++) {
			scanf("%d", &C);
			if (C == 1) {
				scanf("%d %d", &X, &Y);
				update(0, N - 1, 1, X-1, Y);
			}
			else if (C == 2) {
				scanf("%d %d", &L, &R);
				long long res = sum(0, N - 1, 1, L - 1, R - 1);
				ans.push_back(res);
			}
		}
		printf("#%d ", tc);
		for (long long n : ans) {
			printf("%lld ", n);
		}
		printf("\n");
	}
	return 0;

}
