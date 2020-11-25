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
int N,A,B;

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> A >> B;
		int maxn = min(A, B);
		int minn = A + B > N ? A + B - N : 0;
		cout << "#" << t << " " << maxn << " " << minn << "\n";
	}
	return 0;

}
