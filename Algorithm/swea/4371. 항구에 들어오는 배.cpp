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

int T;
int N;
vector<bool> check(1000000001, 0);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int num;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			cin >> num;
			check[num] = true;
			v.push_back(num - 1);
		}
		int maxn = v.back() + 1;
		num = N-1;
		int ans = 0;
		for (int i = 1; i < N; i++) {
			bool up = false;
			int cur = 1+v[i];
			while (cur <= maxn) {
				if (check[cur]) {
					check[cur] = false;
					num--;
					up = true;
				}
				cur += v[i];
			}
			if (up) ans++;
			if (num < 1)break;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
