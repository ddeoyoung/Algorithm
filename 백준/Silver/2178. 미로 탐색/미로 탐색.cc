#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j] - 48;
		}
	}

	sy = 0; sx = 0;
	queue<pair<int, int>> q;
	visited[sy][sx] = 1;
	q.push({sy, sx});
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}

	cout << visited[n-1][m-1]<< '\n';
}