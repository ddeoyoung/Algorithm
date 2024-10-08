// 2024.09.10
// BOJ_9663_NQueen
#include <bits/stdc++.h>
using namespace std;
const int MAX = 16;
int columns[MAX];
int n, res = 0;
bool promising(int row) {
	for (int i = 0; i < row; i++) {
		if (columns[row] == columns[i] ||
			row - i == abs(columns[row] - columns[i])) {
			return false;
		}
	}
	return true;
}

void dfs(int row) {
	if (row == n) {
		res++; return;
	}

	for (int col = 0; col < n; col++) {
		columns[row] = col;
		if (promising(row)) dfs(row + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(0);
	cout << res;
	return 0;
}