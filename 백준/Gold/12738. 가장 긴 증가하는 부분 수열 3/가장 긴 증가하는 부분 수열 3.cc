// 24.11.28
// BOJ_12738_가장긴증가하는부분수열3
#include <bits/stdc++.h>
using namespace std;
int N, n;
vector<int> v, res_v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n + 1000000);
	}
	res_v.push_back(v.front());
	for (int i = 1; i < N; i++) {
		auto it = lower_bound(res_v.begin(), res_v.end(), v[i]);
		if (it == res_v.end()) {
			// 현재 값이 가장 크면 LIS에 추가
			res_v.push_back(v[i]);
		}
		else {
			// 현재 값이 이전 값보다 작으면 작은 위치에 해당하는 값으로 치환
			*it = v[i];
		}
	}
	cout << res_v.size();
	return 0;
}