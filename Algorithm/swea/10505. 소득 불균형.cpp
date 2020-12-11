#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

int T;
int N;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<int> p(N);
		int tot = 0;
		for (int i = 0; i < N; i++) {
			cin >> p[i];
			tot += p[i];
		}
		int m = tot / N;
		int ans = 0;
		for (auto n : p) {
			if (n <= m) ans++;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
