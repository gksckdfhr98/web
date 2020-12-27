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

int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> M;
		vector<int> v;
		long long left = 0, right = 100000000000000;
		long long ans;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		while (left <= right) {
			long long mid = (left + right) / 2;
			long long sum = 0;
			for (int i = 0; i < N; i++) {
				sum += (mid / v[i]);
			}
			if (sum < M) left = mid + 1;
			else {
				ans = mid;
				right = mid - 1;
			}
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;

}
