#include <bits/stdc++.h>
using namespace std;
int N, M, n, pos;
string s, a[100001];
map<string, int> mp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) { // 도감 저장 
		cin >> s;
		mp[s] = i;
		a[i] = s;
	}
	for (int i = 0; i < M; i++) { // 문제 
		cin >> s;
		n = atoi(s.c_str());
		if (n) { // 숫자 
			cout << a[n] << '\n';
		}
		else { // 문자
			cout << mp[s] << '\n';
		}
	}
	return 0;
}