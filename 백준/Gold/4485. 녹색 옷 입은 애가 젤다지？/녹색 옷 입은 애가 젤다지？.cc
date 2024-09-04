// 2024.09.05
// BOJ_4485_녹색옷입은애가젤다지?
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
const int INF = 987654321;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, t, a[130][130], visited[130][130];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		if (n == 0) return 0; // 전체 입력 종료
		t++; // 테스트케이스 번호
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				visited[i][j] = INF;
			}
		}
		queue<pp> q;
		q.push({ 0, 0 });
		visited[0][0] = a[0][0];
		while (q.size()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n ) continue;
				if (visited[ny][nx] > visited[y][x] + a[ny][nx]) {
					visited[ny][nx] = visited[y][x] + a[ny][nx];
					q.push({ ny, nx });
				}
			}
		}
		cout << "Problem " << t << ": " << visited[n - 1][n - 1] << "\n";
	}
}