// 2024.10.30
// BOJ_9251_LCS
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s1 >> s2;

	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 or j == 0) dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) { // 같은 문자가 존재하면
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 문자가 같지 않으면
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[s1.size()][s2.size()];
	return 0;
}