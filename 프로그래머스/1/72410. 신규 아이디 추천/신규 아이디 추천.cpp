#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string id = new_id;
    
    // 1. 대문자를 소문자로 치환
    for(int i = 0; i < id.size(); i++){
        if(isupper(id[i])) id[i] = tolower(id[i]);
    }
    
    // 2. 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자 제거
    for(int i = 0; i < id.size(); i++){
        if(islower(id[i]) || isdigit(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.'){
            continue;
        }
        id.erase(id.begin() + i);
        i--;
    }
    
    // 3. 마침표가 2번 이상 연속된 부분은 하나로 치환
    int dotcnt = 0;
    for(int i = 0; i < id.size(); i++){
        if(dotcnt == 0 && id[i] == '.') dotcnt++; // 마침표 1개
        else if (dotcnt > 0 && id[i] == '.') { // 마침표가 2개 이상 연속시 해당 마침표 삭제
            id.erase(id.begin() + i);
            i--;
        }
        else if (dotcnt > 0 && id[i] != '.') dotcnt = 0; // 연속이 끝났다면 dotcnt 초기화
    }
    
    // 4. 마침표가 처음이나 끝에 위치한다면 제거
    if(id[0] == '.')  id.erase(id.begin());
    if(id[id.size() - 1] == '.') id.erase(id.end() - 1);
    
    // 5. 빈 문자열이라면 "a" 대입
    if(id.size() == 0) id = "a";
    
    // 6. 16자 이상이면 첫 15개의 문자를 제외한 나머지 문자 제거
    //    만약 제거 후 마침표가 끝에 위치한다면 끝에 위치한 마침표 문자 제거
    if(id.size() >= 16){
        id.erase(id.begin() + 15, id.end());
    }
    if(id[id.size() - 1] == '.') id.erase(id.end() - 1);
    
    // 7. 길이가 2자 이하라면 마지막 문자를 길이가 3이 될 때까지 반복
    if(id.size() <= 2){
        while(id.size() < 3){
            char c = id[id.size() - 1];
            id += c;
        }
    }
    
    return id;
}