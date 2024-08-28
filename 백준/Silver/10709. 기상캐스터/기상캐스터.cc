#include <bits/stdc++.h>
using namespace std;
int h, w, cnt, b[101][101];
char a[101][101];
int main(){
	cin >> h >> w;
	cnt = -1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			b[i][j] = cnt;
			if(a[i][j] == 'c'){
				cnt = 0;
				b[i][j] = cnt;
			}
			if(cnt == -1) continue;
			else cnt++;
		}
		cnt = -1;
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
} 