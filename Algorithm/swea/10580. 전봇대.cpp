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
		int a, b;
		vector< pair<int, int> > v;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 1; i < N; i++) {
			int j = i - 1;
			while (j >= 0) {
				if (v[j].second > v[i].second) ans++;
				j--;
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;

}
