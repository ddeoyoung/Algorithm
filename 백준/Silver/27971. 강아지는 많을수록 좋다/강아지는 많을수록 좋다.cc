#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int arr[100001], visited[100001];
queue<pair<int, int>> q;

int bfs() {
	q.push({ 0, 0 });
	visited[0] = 1;
	while (!q.empty()) {
		auto [dog, cnt] = q.front();
		q.pop();
		if (dog == n) return cnt;
		for (int d : {a, b}) {
			int next = dog + d;
			if (next > 100000) continue;
			if (arr[next] || visited[next]) continue;
			visited[next] = 1;
			q.push({ next, cnt + 1 }); // 횟수 증가
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> a >> b;

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j <= r; j++) arr[j] = 1;
	}

	cout << bfs();
	return 0;
}