#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	stack<int> s;
	int num = 1;
	string str;
	while (n--) {
		cin >> t;
		while (num <= t) {
			s.push(num++);
			str += "+\n";
		}
		if (s.top() != t) {
			cout << "NO\n";
			return 0;
		}
		else {
			s.pop();
			str += "-\n";
		}
	}
	cout << str;
}