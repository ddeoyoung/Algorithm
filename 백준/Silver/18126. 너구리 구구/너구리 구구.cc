#include <bits/stdc++.h>
using namespace std;

long long n, res;
vector<pair<int, int>> a[5001]; // to, distance
bool visited[5001];

void go(int from, long long cnt) {
	visited[from] = true;
	res = max(res, cnt); // 누적거리 최대값 업데이트
	for (auto [next, d] : a[from]) {
		if (!visited[next]) {
			go(next, cnt + d);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to, d;
		cin >> from >> to >> d;
		a[from].push_back({ to, d });
		a[to].push_back({ from, d }); // 양방향 간선
	}
	go(1, 0);
	cout << res;
	return 0;
}