// 24.11.29
// BOJ_14003_가장긴증가하는부분수열5
#include <bits/stdc++.h>
using namespace std;
long long N, n, res;
vector<long long> v, res_v, idx;

// v : 입력으로 주어지는 배열 (원본 데이터)
// res_v : LIS를 저장하는 배열
// idx : 데이터가 들어가는 인덱스를 저장하는 배열
// 예) idx[A] = B : v[A]는 res_v[B] 이다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (long long i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	
	// 1. 가장 긴 길이 구하기
	res_v.push_back(v.front());
	idx.push_back(1);
	for (long long i = 1; i < N; i++) {
		auto it = lower_bound(res_v.begin(), res_v.end(), v[i]);
		if (it == res_v.end()) {
			// 현재 값이 가장 크면 LIS에 추가
			res_v.push_back(v[i]);
			idx.push_back(res_v.size()); // 인덱스 추가
		}
		else {
			// 현재 값이 이전 값보다 작으면 작은 위치에 해당하는 값으로 치환
			*it = v[i];
			idx.push_back(it - res_v.begin() + 1); // 인덱스 추가
		}
	}
	res = res_v.size();
	cout << res << "\n";
	res_v.clear();

	// 2. 가장 긴 부분수열 구하기
	for (long long i = N - 1; i >= 0; i--) {
		if (idx[i] == res) {
			res_v.push_back(v[i]);
			res--;
		}
	}
	reverse(res_v.begin(), res_v.end());
	for (long long i : res_v) cout << i << " ";

	return 0;
}