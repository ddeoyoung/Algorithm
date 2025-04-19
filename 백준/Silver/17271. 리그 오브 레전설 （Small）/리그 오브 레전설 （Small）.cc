#include <bits/stdc++.h>
using namespace std;
int n, m, res, dp[10001];
const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1]; // A 스킬 사용
		if (i >= m) {
			dp[i] = (dp[i] + dp[i - m]) % mod; // B 스킬 사용
		}
	}
	cout << dp[n];
	return 0;
}