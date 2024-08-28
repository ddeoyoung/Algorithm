#include <bits/stdc++.h>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, a[104][104], b[104][104], max_h, max_cnt, cnt;
bool visited[104][104];
void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if(!visited[ny][nx] && b[ny][nx] == 1) dfs(ny, nx);
	}
	return;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			max_h = max(max_h, a[i][j]); // 최대 높이
		}
	}
	
	for(int h = 0; h <= max_h; h++){ // 높이별로 측정 
		cnt = 0; // 초기화 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				visited[i][j] = 0; // 초기화
				b[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++){ // 잠기는 지역 구분 (0과 1) 
			for(int j = 0; j < n; j++){
				if(a[i][j] > h) b[i][j] = 1;
				else b[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(b[i][j] && !visited[i][j]){
					cnt++;
					dfs(i, j);
				}
			}
		}
		max_cnt = max(max_cnt, cnt); // 최댓값 구하기
	}
	
	cout << max_cnt;
}