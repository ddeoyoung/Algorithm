// 2024.10.30
// BOJ_12865_평범한배낭
#include <bits/stdc++.h>
using namespace std;
int N, K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	vector<int> w(N + 1, 0);
	vector<int> v(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
		}
	}
	cout << dp[N][K];

	return 0;
}