// 2024.09.06
// BOJ_11723_집합
#include <bits/stdc++.h>
using namespace std;
int m, x;
string s;
map<int, int> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			if (mp.find(x) != mp.end()) continue;
			else mp.insert({x, 1});
		}
		else if (s == "remove") {
			cin >> x;
			if (mp.find(x) == mp.end()) continue;
			else mp.erase(x);
		}
		else if (s == "check") {
			cin >> x;
			if (mp.find(x) != mp.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			if (mp.find(x) != mp.end()) mp.erase(x);
			else mp.insert({ x, 1 });
		}
		else if (s == "all") {
			for (int j = 1; j <= 20; j++) mp.insert({ j, 1 });
		}
		else if (s == "empty") mp.clear();
	}
	return 0;
}