// 2024.09.06
// BOJ_11723_집합_비트마스킹풀이
#include <bits/stdc++.h>
using namespace std;
int m, n, x;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x; n |= (1 << x);
		}
		else if (s == "remove") {
			cin >> x; n &= ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			if (n & (1 << x)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x; n ^= (1 << x);
		}
		else if (s == "all") n = (1 << 21) - 1;
		else if (s == "empty") n = 0;
	}
}