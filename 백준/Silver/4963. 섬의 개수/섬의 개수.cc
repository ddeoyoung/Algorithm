#include <bits/stdc++.h>
using namespace std;

int w, h, ny, nx, res, a[51][51];
int dy[8] = { -1, 0, 1, 0 , -1, -1, 1, 1};
int dx[8] = { 0, 1, 0, -1 , -1, 1, 1, -1};
int visited[51][51];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if (a[ny][nx] == 1 && !visited[ny][nx]) dfs(ny, nx);
	}
	return;
}

int main() {
	
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		res = 0;
		memset(visited, 0, sizeof(visited));
		memset(a, 0, sizeof(a));
		

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					res++; dfs(i, j);
				}
			}
		}

		cout << res << "\n";
		
	}

	return 0;
}