// 24.11.26
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
		temp[i].push_back(n);
		for (int j = 0; j < v.size(); j++) {
			if (v[i] > v[j]) {
				if (dp[i] < dp[j] + 1) {
					temp[i].clear();
					temp[i] = temp[j];
					temp[i].push_back(v[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (res_v.size() < temp[i].size()) res_v = temp[i];
	}

	cout << res_v.size() << "\n";
	for (int i : res_v) cout << i << " ";
	return 0;
}