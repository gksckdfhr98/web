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

int N;
int n, a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> n;
		multiset<int> se;
		se.insert(n);
		int mid = n;
		long long ans = 0;
		auto it = se.begin();
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			se.insert(a);
			se.insert(b);
			if (mid <= a && mid <= b) {
				it++;
			}
			else if(a<=mid&&mid<=b){}
			else if(a>=mid&&mid>=b){}
			else if (a <= mid && b <= mid) {
				it--;
			}
			ans += (*it);
			ans %= 20171109;
			mid = (*it);
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;

}
