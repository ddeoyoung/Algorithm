// 2024.10.29
// BOJ_16953_AB
#include <bits/stdc++.h>
using namespace std;
long A, B, cnt;

int main() {
	cin >> A >> B;
	cnt = 1;
	while (true) {
		if (A == B) break;
		else if (A > B) {
			cnt = -1;
			break;
		}

		if (B % 2 == 0) B /= 2;
		else if (B % 10 == 1) B = (B - 1) / 10;
		else {
			cnt = -1;
			break;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}