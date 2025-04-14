#include <bits/stdc++.h>
using namespace std;

int m, n, res, l, r, mid, mx, cnt;
vector<int> v;

int main() {
	cin >> m >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	l = 1;
	r = *max_element(v.begin(), v.end());
	while (l <= r) {
		cnt = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < n; i++) {
			cnt += v[i] / mid;
		}
		if (cnt < m) r = mid - 1;
		else {
			res = mid;
			l = mid + 1;
		}
	}
	cout << res;
	return 0;
}