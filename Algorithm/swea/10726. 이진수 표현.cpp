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
string s;

bool check(int N, int M) {
	for (int i = 0; i < N; i++) {
		if (M % 2 == 0) return false;
		M /= 2;
	}
	return true;
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;
		string ans = "ON";
		if (!check(N, M)) {
			ans = "OFF";
		}
		cout << "#" << t << " " + ans + "\n";
	}
	return 0;

}
