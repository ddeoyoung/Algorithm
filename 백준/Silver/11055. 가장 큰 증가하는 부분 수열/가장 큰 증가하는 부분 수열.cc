// 24.11.26
// BOJ_11055_가장큰증가하는부분수열
#include <bits/stdc++.h>
using namespace std;

int N, dp[1001], n, res;
vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		for (int j = 0; j < v.size(); j++) {
			if (v[i] > v[j]) { // 증가하는
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += v[i];
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}