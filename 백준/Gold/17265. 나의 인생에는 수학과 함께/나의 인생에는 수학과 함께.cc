#include <bits/stdc++.h>
using namespace std;
int n;
int mx = INT_MIN;
int mn = INT_MAX;
int dy[2] = { 1, 0 }; // 오른쪽, 아래 이동
int dx[2] = { 0, 1 };
char a[5][5];

int cal(int first, char op, int second) {
    if (op == '+') return first + second;
    if (op == '-') return first - second;
    if (op == '*') return first * second;
    return 0;
}

void dfs(int y, int x, int cur, char oper) {
    if (y == n - 1 && x == n - 1) {
        mx = max(mx, cur);
        mn = min(mn, cur);
        return;
    }

    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= n || nx >= n) continue;

        if (isdigit(a[ny][nx])) { // 숫자칸
            int num = a[ny][nx] - '0';
            int next = cal(cur, oper, num);
            dfs(ny, nx, next, oper); // 계산된 값으로 이동
        }
        else { // 연산자칸
            dfs(ny, nx, cur, a[ny][nx]); // 연산자 업데이트
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
    dfs(0, 0, a[0][0] - '0', ' ');
	cout << mx << " " << mn;
	return 0;
}