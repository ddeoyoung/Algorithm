#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int solution(vector<int> nums)
{
    int answer = 0;
    for(int i = 0; i < nums.size(); i++){
        int n = nums[i];
        if (mp.find(n) == mp.end()) {
            mp.insert({n, 1});
        }
        else if (mp.find(n) != mp.end()){
            mp[n]++;
        }
    }
    
    //for(auto it : mp) cout << it.second << " ";
    int cnt = mp.size();
    if(cnt < nums.size() / 2) answer = cnt;
    else answer = nums.size() / 2;
    
    return answer;
}