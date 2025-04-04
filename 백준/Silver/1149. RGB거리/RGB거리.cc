// 2024.10.29
// BOJ_1149_RGB거리
#include <bits/stdc++.h>
using namespace std;
int N, a[1001][3], c[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c[0] >> c[1] >> c[2];
		a[i][0] = min(a[i - 1][1], a[i - 1][2]) + c[0];
		a[i][1] = min(a[i - 1][0], a[i - 1][2]) + c[1];
		a[i][2] = min(a[i - 1][0], a[i - 1][1]) + c[2];
	}
	cout << min(min(a[N][0], a[N][1]), a[N][2]);
	return 0;
}