#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;
string solution(vector<string> p, vector<string> c) {
    string answer = "";
    for (int i = 0; i < p.size(); i++) {
        if (mp.find(p[i]) == mp.end()) mp.insert({ p[i], 1 });
        else mp[p[i]]++;
    }
    // for (auto it : mp) cout << it.first << " ";
    for (int i = 0; i < c.size(); i++){
        if (mp.find(c[i]) != mp.end()) mp[c[i]]--;
    }
    //for (auto it : mp) cout << it.first << " " << it.second << "\n";
    for (auto it : mp){
        if (it.second != 0) answer = it.first;
    }
    return answer;
}