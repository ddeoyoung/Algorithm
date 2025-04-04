#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int answer = INT_MIN;
int temp, sum[100001],n,k; 
int main() {
	cin >> n >> k; 
	for (int i = 1; i <= n; i++) {
		cin >> temp; 
		sum[i] = sum[i - 1] + temp; 
	}
	for (int i = k; i <= n; i++) {
		answer = max(answer, sum[i] - sum[i - k]);
	}
	cout << answer; 	
}