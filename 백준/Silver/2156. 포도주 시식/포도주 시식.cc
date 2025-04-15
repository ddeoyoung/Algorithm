#include <bits/stdc++.h>
using namespace std;
int n, a[10005], dp[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[0]; return 0;
	}
	if (n == 2) {
		cout << a[0] + a[1]; return 0;
	}
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = max({ dp[1], dp[0] + a[2], a[1] + a[2] });
	for (int i = 3; i < n; i++) {
		dp[i] = max({ 
			dp[i - 1], // 현재 안 마시는 경우
			dp[i - 2] + a[i], // 직전은 건너뛰고 지금 마시는 경우
			dp[i - 3] + a[i - 1] + a[i] }); // 연속 두 잔 마시고 그 전은 건너뛴 경우
	}
	cout << dp[n - 1];
	return 0;
}