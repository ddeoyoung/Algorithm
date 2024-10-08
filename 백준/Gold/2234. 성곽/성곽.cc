// 2024.09.04
// BOJ_2234_성곽
#include <bits/stdc++.h>
using namespace std;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int n, m, mx, mx2, idx, a[51][51], visited[51][51], a_size[2504];

int dfs(int y, int x, int idx) {
	if (visited[y][x]) return 0;
	visited[y][x] = idx;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		if (!(a[y][x] & (1 << i))) { // 벽 체크
			int ny = y + dy[i];
			int nx = x + dx[i];
			ret += dfs(ny, nx, idx);
		}
	}
	return ret;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	// 1. 방의 개수, 2. 넓이 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				idx++;
				a_size[idx] = dfs(i, j, idx);
				mx = max(mx, a_size[idx]);
			}
		}
	}

	// 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
	int cur_size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 1 < m) {
				int cur = visited[i][j];
				int next = visited[i][j + 1];
				if (cur != next) { // 다른 방
					cur_size = a_size[cur] + a_size[next];
					mx2 = max(mx2, cur_size);
				}
			}
			if (i + 1 < n) {
				int cur = visited[i][j];
				int next = visited[i + 1][j];
				if (cur != next) { // 다른 방
					cur_size = a_size[cur] + a_size[next];
					mx2 = max(mx2, cur_size);
				}
			}
		}
	}

	cout << idx << "\n";
	cout << mx << "\n";
	cout << mx2 << "\n";
	return 0;
}