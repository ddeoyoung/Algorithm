#include <bits/stdc++.h>
using namespace std;
int n, size, a[64][64];
string s, res;
int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

bool check(int x, int y, int size){
	for(int i = x; i < x + size; i++){ // 모두 0 or 1 체크 
		for(int j = y; j < y + size; j++){
			if(a[x][y] == a[i][j]) {
				if(i == x + size - 1 && j == y + size - 1){
					return true;
				}
				continue;
			}
			else return false;
		}
	}
}

void go(int x, int y, int size){
	if(check(x, y, size) == true){
		cout << a[x][y];
		return;
	}
	
	cout << "(";
	size /= 2;
	for(int i = 0; i < 4; i++){
		int nx = x + size * dy[i];
		int ny = y + size * dx[i];
		go(nx, ny, size);
	}
	cout << ")";
	return;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			a[i][j] = s[j] - 48;
		}
	}

	go(0, 0, n);
}