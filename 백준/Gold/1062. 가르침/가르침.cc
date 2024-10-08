// 2024.09.06
// BOJ_1062_가르침
#include <bits/stdc++.h>
using namespace std;
int n, k, a[26], mx, res;
string s[51];
vector<char> v, temp;

int check(vector<char> temp) {
    int cnt = 0;
    memset(a, 0, sizeof(a));
    a['a' - 'a']++; a['n' - 'a']++; a['t' - 'a']++; a['i' - 'a']++; a['c' - 'a']++;
    for (char i : temp) a[i - 'a']++;
    for (int i = 0; i < n; i++) {
        string str = s[i];
        bool canRead = true;
        for (int j = 4; j < str.size() - 4; j++) {
            if (!a[str[j] - 'a']) {
                canRead = false;
                break;
            }
        }
        if (canRead) cnt++;
    }
    return cnt;
}

void combi(int start, vector<char>& v) {
    if (temp.size() == k - 5) {
        res = check(temp);
        mx = max(mx, res);
        return;
    }
    for (int i = start + 1; i < v.size(); i++) {
        temp.push_back(v[i]);
        combi(i, v);
        temp.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i].size() <= 8) continue;
        for (int j = 4; j < s[i].size() - 4; j++) {
            a[s[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (i + 'a' != 'a' && i + 'a' != 'n' && i + 'a' != 't' && i + 'a' != 'i' && i + 'a' != 'c') {
            v.push_back(i + 'a');
        }
    }

    if (k == 26) {  // 모든 문자를 배울 수 있는 경우
        cout << n;  // 모든 단어를 읽을 수 있음
        return 0;
    }

    combi(-1, v);
    cout << mx;
    return 0;
}
