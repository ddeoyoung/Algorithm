// 1-G
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
string str, pat, a, b;

int main() {
	cin >> N >> pat;
	int pos = pat.find('*');
	a = pat.substr(0, pos);
	b = pat.substr(pos + 1);

	for (int i = 0; i < N; i++) { // N번 반복 
		cin >> str;
		int IsTrue = 1;

		if (str.size() < a.size() + b.size()) {
			cout << "NE" << '\n';
			continue;
		}

		if (a == str.substr(0, a.size()) && b == str.substr(str.size() - b.size()))
		{
			cout << "DA" << '\n';
		}
		else cout << "NE" << '\n';
	}

	return 0;
}