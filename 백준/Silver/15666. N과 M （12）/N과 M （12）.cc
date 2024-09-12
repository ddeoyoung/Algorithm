// 2024.09.12
// BOJ_15666_N과M12
#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], b[10];
void dfs(int num, int len) {
    if (len == m) {
        for (int i = 0; i < m; i++)
            cout << b[i] << ' ';
        cout << '\n';
        return;
    }
    int temp = 0;
    for (int i = num; i < n; i++) {
        if (temp != a[i]) {
            b[len] = a[i];
            temp = b[len];
            dfs(i, len + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0, 0);
    return 0;
}