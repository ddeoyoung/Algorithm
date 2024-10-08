// 2024.09.08
// BOJ_1916_최소비용구하기
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int n, m, cost[1003], res;
vector<pp> v[1003];
map<int, pp> mp;

void go(int start) {
	priority_queue<pp, vector<pp>, greater<pp>> pq;
	pq.push({ 0, start });
	cost[start] = 0;
	while (!pq.empty()) {
		int cur_cost = pq.top().first; // 다음 도시
		int cur = pq.top().second; // 비용
		pq.pop();

		if (cost[cur] < cur_cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_cost = cur_cost + v[cur][i].second;
			if (cost[next] > next_cost) {
				pq.push({ next_cost, next });
				cost[next] = next_cost;
			}
		}
	}
}


int main() {
	cin >> n >> m;
	v[0].push_back({ 0, 0 });
	memset(cost, 98765432, sizeof(cost));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	int start, end;
	cin >> start >> end;
	go(start);
	cout << cost[end];
	return 0;
}