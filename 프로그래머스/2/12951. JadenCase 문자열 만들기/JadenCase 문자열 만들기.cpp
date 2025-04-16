#include <bits/stdc++.h>
using namespace std;

string s, ans;

vector<string> split(string input, string del){
    vector<string> res;
    int pos = 0;
    string temp = "";
    
    while((pos = input.find(del)) != string::npos){
        temp = input.substr(0, pos);
        res.push_back(temp);
        input.erase(0, pos + del.length());
    }
    res.push_back(input);
    return res;
}

string solution(string s) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;
    vector<string> v = split(s, " ");

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(j == 0) {
                if(islower(v[i][j])) v[i][j] = toupper(v[i][j]); // 대문자 변환
            }
            else v[i][j] = tolower(v[i][j]); // 소문자 변환
            ans += v[i][j];
        }
        if(i == v.size() - 1) continue;
        ans += " ";
    }
    return ans;
}