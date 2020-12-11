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


int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		int b_pos = 1, o_pos = 1;
		int b_time = 0, o_time = 0;
		int time = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			char c;
			int pos;
			cin >> c;
			cin >> pos;
			if (c == 'B') {
				if (abs(pos - b_pos) > time-b_time) {
					time = abs(pos - b_pos) + 1 + b_time;
				}
				else time += 1;
				b_pos = pos;
				b_time = time;
			}
			else {
				if (abs(pos - o_pos) > time - o_time) {
					time = abs(pos - o_pos) + 1 + o_time;
				}
				else time += 1;
				o_pos = pos;
				o_time = time;
			}
		}
		cout << "#" << t << " " << time << "\n";
	}
	return 0;

}
