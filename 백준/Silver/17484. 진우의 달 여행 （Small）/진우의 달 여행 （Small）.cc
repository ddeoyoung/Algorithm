#include <bits/stdc++.h>
using namespace std;
int n, m, a[6][6], ny, nx;
int res = INT_MAX;
int dy[3] = { 1, 1, 1 };
int dx[3] = { -1, 0, 1 };

void dfs(int y, int x, int cnt, int prev_dir) {
	cnt += a[y][x];
	if (y == n - 1) {
		res = min(res, cnt);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (i == prev_dir) continue; // 같은 방향은 건너뛰기
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		dfs(ny, nx, cnt, i);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		dfs(0, i, 0, -1);
	}

	cout << res;
	return 0;
}