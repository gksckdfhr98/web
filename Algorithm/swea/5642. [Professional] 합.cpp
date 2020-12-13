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

#define MAXN 1234567891
int N;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		vector<int> num(N);
		ans = -1001;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
			ans = max(ans, num[i]);
		}
		if (ans <= 0) {
			printf("#%d %d\n", tc, ans);
			continue;
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += num[i];
			if (sum < 0)sum = 0;
			ans = max(ans, sum);
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
