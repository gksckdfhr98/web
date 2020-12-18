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

int N;
vector<int> v;
vector< pair<int, int> > num;
int chk[1000005];

void sol(int n) {
	int division;
	if (chk[n] != 0) return;

	for (int i = 0; i < num.size(); i++) {
		if (n % num[i].first != 0 || num[i].first == 1) continue;
		division = n / num[i].first;
		if (chk[division] == 0) sol(division);
		if(chk[division] != 0) {
			if (chk[n] == 0) chk[n] = chk[division] + num[i].second + 1;
			else chk[n] = min(chk[n], chk[division] + num[i].second + 1);
		}
	}
}

void make_num(int a,int n) {
	for (int i = 0; i < v.size(); i++) {
		if (a == 0 && v[i] == 0) continue;
		if (a * 10 + v[i] > N) return;
		num.push_back({a*10+v[i],n+1});
		chk[a * 10 + v[i]] = n + 1;
		make_num(a * 10 + v[i], n + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(chk, 0, sizeof(chk));
		v.clear(); num.clear();
		for (int i = 0; i < 10; i++) {
			int a;
			cin >> a;
			if (a == 1) v.push_back(i);
		}
		cin >> N;
		make_num(0, 0);
		sol(N);
		if(chk[N]!=0)
			printf("#%d %d\n", tc, chk[N]+1);
		else
			printf("#%d %d\n", tc, -1);
	}
	return 0;

}
