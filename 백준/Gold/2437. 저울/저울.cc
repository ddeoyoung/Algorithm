#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<int> v(1001);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	res = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > res) { // i번째 추 무게가 res보다 크면
			cout << res;
			break;
		}
		res += v[i]; // i번째 추 무게가 res 작으면
		if (i == v.size() - 1) cout << res; // 모두 탐색하면 종료
	}

	return 0;
}