// 2024.08.29
// BOJ 13913 숨바꼭질4
#include <bits/stdc++.h>
using namespace std;
int n, k, x, nx, res, p[200004], a[200004];
vector<int> v;

int cal(int i, int x) {
	if (i == 0) return x - 1;
	else if (i == 1) return x + 1;
	else if (i == 2) return x * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	a[n] = 1;
	while (q.size()) {
		x = q.front();
		q.pop();
		if (x == k) {
			res = a[k];
			break;
		}
		for (int i = 0; i < 3; i++) {
			nx = cal(i, x);
			if (nx < 0 || nx > 100000) continue;
			if (!a[nx]) {
				a[nx] = a[x] + 1;
				q.push(nx);
				p[nx] = x; // prev 경로 저장
			}
		}
	}
	// p[k] 부터 p[n]이 아닐 때까지 경로 역추적
	for (int i = k; i != n; i = p[i]) {
		v.push_back(i);
	}
	v.push_back(n); // 수빈이 처음 위치 저장
	reverse(v.begin(), v.end());
	cout << a[k] - 1 << "\n";
	for (int i : v) cout << i << " ";
	return 0;
}