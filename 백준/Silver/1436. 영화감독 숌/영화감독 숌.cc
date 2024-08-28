// 2024.06.25

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 666
	// 1666 2666 3666 4666 5666
	// 6660 6661 6662 6663 6663 6665 6666 6667 6668 6669
	// 7666 8666 9666
	// 10666 11666 12666 13666 14666 15666
	// 16660 16661 16662 16663 16664 16665 16666 16667 16668 16669
	// 17666

	int n;
	cin >> n;
	string s = "";
	int res = 665;

	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			res++;
			s = to_string(res);
			if (s.find("666") != -1)
			{
				break;
			}
		}
	}
	cout << res << endl;

	return 0;
}