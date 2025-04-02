#include <bits/stdc++.h>
using namespace std;

int lx, ly, rx, ry;

// 드래그 한 거리 = |rdx - lux| + |rdy - luy|

vector<int> solution(vector<string> w) {
    vector<int> ans;
    int lx = INT_MAX; int ly = INT_MAX;
    
    for(int i = 0; i < w.size(); i++){
        for(int j = 0; j < w[i].size(); j++){
            if(w[i][j] == '#') { // 파일이라면
                lx = min(lx, i);
                ly = min(ly, j);
                rx = max(rx, i);
                ry = max(ry, j);
            }
        }
    }
    
    ans.push_back(lx);
    ans.push_back(ly);
    ans.push_back(rx + 1);
    ans.push_back(ry + 1);
    
    return ans;
}