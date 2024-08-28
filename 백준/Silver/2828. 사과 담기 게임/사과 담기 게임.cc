#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, a, b;
queue<int> q;
bool check(int b){
	for(int i = 0; i < m; i++){
		if(b + i == a) {
			return true;
		}
	}
	return false;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> a;
		q.push(a);
	}
	b = 1;
	while(q.size()){
		a = q.front();
		q.pop();
		while(true){
			bool IsHit = check(b);
			if(IsHit == true) break;
			else {
				if(b < a) b += 1;
				else if(b > a) b -= 1;
				cnt++;
			}
		}
	}
	cout << cnt;
} 