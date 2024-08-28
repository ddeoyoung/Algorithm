#include <bits/stdc++.h>
using namespace std;
string s, temp;
int main() {
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if((s[i] >= 65 && s[i] <= 77)
		|| (s[i] >= 97 && s[i] <= 109)) {
			temp += s[i] + 13;
		}
		else if ((s[i] >= 78 && s[i] <= 90)
		|| (s[i] >= 110 && s[i] <= 122)){
			temp += s[i] - 13;
		}
		else temp += s[i];
	}
	cout << temp;
}