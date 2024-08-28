#include <bits/stdc++.h>
using namespace std;
unsigned long long res;
int n, cnt;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n){
		cnt = 1; res = 1;
		while(true){
			if(res % n == 0){
				cout << cnt << "\n";
				break;
			}
			//res += pow(10, cnt);
			res = ((res * 10) % n) + 1;
			cnt++;
		}
	}
	return 0;
}