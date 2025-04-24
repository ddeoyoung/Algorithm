#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int visited[1000001];

string bfs() {
	q.push(0);
	visited[0] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == n && visited[n] - 1 <= k) return "minigimbob"; // 계단 도달

		int nx1 = cur + 1;
		int nx2 = cur + (cur / 2);

		if (nx1 <= 1000001 && !visited[nx1]) { // 1번
			visited[nx1] = visited[cur] + 1;
			q.push(nx1);
		}
		if (nx2 <= 1000001 && !visited[nx2]) { // 2번
			visited[nx2] = visited[cur] + 1;
			q.push(nx2);
		}
	}
	return "water";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cout << bfs();
	return 0;
}