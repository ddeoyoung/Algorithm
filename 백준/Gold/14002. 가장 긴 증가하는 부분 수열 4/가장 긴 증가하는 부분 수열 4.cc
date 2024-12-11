// 24.12.11
// BOJ_14002_가장긴증가하는부분수열4
#include <bits/stdc++.h>
using namespace std;
int N, n, res, dp[1001];
vector<int> v, temp[1001], res_v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		dp[i] = 1;
		for (int j = 0; j < v.size(); j++) {
			if (v[i] > v[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
		}
		res = max(res, dp[i]);
	}
	cout << res << "\n";

	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == res) {
			res_v.push_back(v[i]);
			res--;
		}
	}
	reverse(res_v.begin(), res_v.end());
	for (int i : res_v) cout << i << " ";
	return 0;
}