// 2024.09.02
// BOJ_1987_알파벳
#include <bits/stdc++.h>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int r, c, res, b[30], ny, nx;
char a[30][30];

void dfs(int y, int x, int cnt) {
	res = max(res, cnt);
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i]; nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int next = a[ny][nx] - 65;
		if (b[next] == 0) {
			b[next] = 1;
			dfs(ny, nx, cnt + 1);
			b[next] = 0; // 원복
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	b[a[0][0] - 65] = 1;
	dfs(0, 0, 1);
	cout << res;
	return 0;
}