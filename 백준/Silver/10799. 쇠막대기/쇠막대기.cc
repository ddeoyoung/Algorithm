#include <bits/stdc++.h>
using namespace std;

int res, cur;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' && s[i + 1] == ')') { // 레이저로 자르면 막대 수만큼 더한다
			res += cur;
			i++;
		}
		else if (s[i] == '(') { // 막대 수 증가
			cur++;
		}
		else if (s[i] == ')') { // 막대 수 감소, 막대 조각 + 1
			cur--;
			res++;
		}
	}

	cout << res;
	return 0;
}