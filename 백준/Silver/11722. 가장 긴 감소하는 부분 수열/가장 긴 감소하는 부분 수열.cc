// 24.11.26
// BOJ_11722_가장긴감소하는부분수열
#include <bits/stdc++.h>
using namespace std;
int N, n, dp[1001], res;
vector<int> v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		int cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[i] < v[j]) {
				if (cnt < dp[j]) cnt = dp[j];
			}
		}
		dp[i] = cnt + 1;
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}