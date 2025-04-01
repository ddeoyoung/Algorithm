#include <bits/stdc++.h>
using namespace std;

long long a[200], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	a[1] = 1; a[2] = 1; a[3] = 1;

	for (int i = 4; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 3];
	}
	cout << a[n];
	return 0;
}