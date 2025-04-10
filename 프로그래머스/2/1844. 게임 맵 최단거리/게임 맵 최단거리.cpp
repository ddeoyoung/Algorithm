#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, y, x, ny, nx, visited[101][101];

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    m = maps[0].size();
    n = maps.size();
    queue<pp> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || maps[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    answer = visited[n-1][m-1];
    if(answer == 0) answer = -1;
    return answer;
}