#include <bits/stdc++.h>
using namespace std;
string s;

bool checkvowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i'
		|| c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> s;
		if (s == "end") return 0;
		bool b = true;

		// 1번 조건
		if (s.find("a") == string::npos
			&& s.find("e") == string::npos
			&& s.find("i") == string::npos
			&& s.find("o") == string::npos
			&& s.find("u") == string::npos) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		// 2번 조건
		if (s.size() > 2) {
			for (int i = 0; i < s.size() - 2; i++) {
				if (checkvowel(s[i])) { // 모음 
					if (checkvowel(s[i + 1])) {
						if (checkvowel(s[i + 2])) b = false;
					}
				}

				else { // 자음
					if (!checkvowel(s[i + 1])) {
						if (!checkvowel(s[i + 2])) b = false;
					}
				}
			}
		}
		if (b == false) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		// 3번 조건
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == 'e' || s[i] == 'o') continue;
			if (s[i] == s[i + 1]) b = false;
		}
		if (b == false) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		cout << "<" << s << "> is acceptable.\n";
	}
}