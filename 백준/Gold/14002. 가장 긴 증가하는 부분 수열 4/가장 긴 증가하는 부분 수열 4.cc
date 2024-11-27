// 24.11.26
// BOJ_14002_가장긴증가하는부분수열4
#include <bits/stdc++.h>
using namespace std;
int N, n, res, dp[1001];
vector<int> v, temp[1001], res_v;
int main() {
	cin >> N;
	// 가장 긴 길이 구하기
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		dp[i] = 1;
		for (int j = 0; j < v.size(); j++) {
			if (v[i] > v[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
		res = max(res, dp[i]);
	}
	// 출력
	cout << res << "\n";

	// 가장 긴 부분수열 구하기
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == res) {
			res_v.push_back(v[i]);
			res--;
		}
	}
	reverse(res_v.begin(), res_v.end());

	// 출력
	for (int i : res_v) cout << i << " ";
	return 0;
}