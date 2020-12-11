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
using namespace std;


int num[100000];
int dp[1000001];
int T;
int N;



int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(dp, 0, sizeof(0));
		for (int i = 0; i < N; i++) {
			cin >> num[i];
			dp[num[i]] = 1;
		}
		sort(num, num+N);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int tmp = num[i] + num[i];
			while (tmp <= num[N - 1]) {
				if (dp[tmp]) {
					dp[tmp] = max(dp[tmp], dp[num[i]]+1);
				}
				tmp += num[i];
			}
			ans = max(ans, dp[num[i]]);
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
