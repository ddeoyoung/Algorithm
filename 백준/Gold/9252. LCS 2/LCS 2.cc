// 2024.10.30
// BOJ_9252_LCS2
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<char> res;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s1 >> s2;

	// LCS 길이 구하기
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 or j == 0) dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; // 같은 문자면
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 문자가 같지 않으면
		}
	}
	cout << dp[s1.size()][s2.size()] << "\n";

	// LCS 구하기 (백트래킹)
	int i = s1.size();
	int j = s2.size();
	int cur = dp[i][j];
	while (true) {
		if (cur == 0) break; // 0이면 종료
		if (cur == dp[i - 1][j]) i = i - 1;
		else if (cur == dp[i][j - 1]) j = j - 1;
		else { // 같은 값이 없으면 res에 넣고 이동
			res.push_back(s1[i - 1]);
			i = i - 1;
			j = j - 1;
		}
		cur = dp[i][j];
	}
	reverse(res.begin(), res.end());
	for (char c : res) cout << c;
	return 0;
}