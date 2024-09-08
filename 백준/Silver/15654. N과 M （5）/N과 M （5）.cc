// 2024.09.09
// BOJ_15654_N과M5
#include <bits/stdc++.h>
using namespace std;
int n, m, num, a[9], b[9];
bool visited[9];
void dfs(int num, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << b[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            b[cnt] = a[i - 1];
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
	dfs(1, 0);
}