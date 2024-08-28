#include <bits/stdc++.h>
using namespace std;
long long m;
int n, cnt, a[15004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] + a[j] == m) cnt++;
		}
	}
	cout << cnt;
	return 0;
} 